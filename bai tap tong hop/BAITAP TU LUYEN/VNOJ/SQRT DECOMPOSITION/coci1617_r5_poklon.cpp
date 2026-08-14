#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e5;
const int blockSize = 710;
int n,q,cnt[MM + 5],a[MM + 5],ans[MM + 5],cur_res = 0;
struct dl{int l,r,id;} qr[MM + 5];

void compress(int a[])
{
    vector<int> v;
    for(int i = 1;i <= n;i++) 
        v.push_back(a[i]);

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++)  
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
}

bool cmp(dl a,dl b)
{
    int pa = a.l / blockSize;
    int pb = b.l / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
}

void update(int l,int x)
{
    if(cnt[ a[l] ] == 2) cur_res--;
    cnt[ a[l] ] += x;
    if(cnt[ a[l] ] == 2) cur_res++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    compress(a);
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1,r = 0;
    for(int i = 1;i <= q;i++) {
        while(l < qr[i].l) update(l++,-1);
        while(l > qr[i].l) update(--l,1);
        while(r < qr[i].r) update(++r,1);
        while(r > qr[i].r) update(r--,-1); 
        ans[ qr[i].id ] = cur_res;
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

    return 0;
}