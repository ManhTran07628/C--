#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5;
const int blockSize = 320;
int n,q,a[MM + 5],cnt[MM + 5],cur_res[MM + 5],ans[MM + 5];
struct dl{int l,r,x,id;} qr[MM + 5];

bool cmp(dl a,dl b)
{
    int pa = a.l / blockSize;
    int pb = b.l / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
}

void update(int l,int v)
{
    // add
    if(v == 1) {
        cur_res[ cnt[ a[l] ] ]--;
        cnt[ a[l] ]++;
        cur_res[ cnt[ a[l] ] ]++;
    }
    else { // del
        cur_res[ cnt[ a[l] ] ]--;
        cnt[ a[l] ]--;
        cur_res[ cnt[ a[l] ] ]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].x;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1,r = 0;
    for(int i = 1;i <= q;i++) {
        // cout << qr[i].l << ' ' << qr[i].r << ' ' << qr[i].x << '\n';
        while(l < qr[i].l) update(l++,-1);
        while(l > qr[i].l) update(--l,1);
        while(r < qr[i].r) update(++r,1);
        while(r > qr[i].r) update(r--,-1);
        ans[ qr[i].id ] = cur_res[ qr[i].x ];
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}