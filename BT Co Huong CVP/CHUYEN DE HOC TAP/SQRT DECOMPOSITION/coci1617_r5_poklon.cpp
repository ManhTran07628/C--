#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e5 + 7;
const int blockSize = 710;
int n,q,a[MM],cnt[MM],cur_res = 0,ans[MM];
struct Query{int l,r,id;} qr[MM];

bool cmp(Query a, Query b)
{
    int pa = a.l / blockSize;
    int pb = b.l / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
}

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
    }
}

void update(int x,int val)
{
    if(val == -1) {
        cur_res -= (cnt[x] == 2);
        --cnt[x];
        cur_res += (cnt[x] == 2);
    }
    else {
        cur_res -= (cnt[x] == 2);
        ++cnt[x];
        cur_res += (cnt[x] == 2);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    coordcompress();
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1, r = 0;
    for(int i = 1;i <= q;i++) {
        while(l < qr[i].l) update(a[l++],-1);
        while(l > qr[i].l) update(a[--l],1);
        while(r < qr[i].r) update(a[++r],1);
        while(r > qr[i].r) update(a[r--],-1);

        ans[ qr[i].id ] = cur_res;
    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}