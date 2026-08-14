#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5;
const int blockSize = 450;
int n,a[MM + 7],newval[MM + 7];
ll cur_res = 0,cnt[MM + 7],q,ans[MM + 7];
struct dl{int l,r,id;} qr[MM + 7];
set<int> st[MM];
bool cmp(dl a,dl b)
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
        int f = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
        newval[ f ] = a[i];
        a[i] = f;
    }
        

}

void update(int x,int type)
{
    if(type == 1) {
        if(cnt[x] > 0) st[ cnt[x] ].erase(x);
        cnt[x]++;
        if(cnt[x] > 0) st[ cnt[x] ].insert(x);
        if(cnt[x] > cur_res) cur_res = cnt[x];
    }
    else {
        if(cnt[x] > 0) st[ cnt[x] ].erase(x);
        cnt[x]--;
        if(cnt[x] > 0) st[ cnt[x] ].insert(x);
        while(cur_res > 0 && st[cur_res].empty()) {
            cur_res--;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    coordcompress();
    cin >> q;
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

        ans[ qr[i].id ] = newval[ *st[ cur_res ].begin() ];
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}