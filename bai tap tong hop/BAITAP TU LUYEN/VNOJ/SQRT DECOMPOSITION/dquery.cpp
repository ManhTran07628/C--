#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
const int blockSize = 175;
int n,q,a[MM + 5],cnt[MM + 5],ans[MM + 5],cur_res = 0;
struct dl{int l,r,id;} qr[MM + 5];

bool cmp(dl a, dl b)
{
    int pa = (a.l + blockSize - 1) / blockSize;
    int pb = (b.l + blockSize - 1) / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
}

void query(int l,int x)
{
    if(x == 1) {
        if(cnt[ a[l] ] == 0) cur_res++;
        cnt[ a[l] ]++;
    }
    else {
        if(cnt[ a[l] ] == 1) cur_res--;
        cnt[ a[l] ]--;
    }
    // if(cnt[ a[l] ] == 1) cur_res--;
    // cnt[ a[l] ] += x;
    // if(cnt[ a[l] ] == 1) cur_res++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> q;
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1, r = 0;
    for(int i = 1;i <= q;i++) {
        // cout << qr[i].l << ' ' << qr[i].r << '\n';
        while(l < qr[i].l) query(l++,-1);
        while(l > qr[i].l) query(--l,1);
        while(r < qr[i].r) query(++r,1);
        while(r > qr[i].r) query(r--,-1);
        ans[ qr[i].id ] = cur_res;
    }
    for(int i = 1;i <= q;i++)
        cout << ans[i] << '\n';
    return 0;
}