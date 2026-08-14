#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,q,a[MM],L[MM],R[MM],ans[MM];
struct QR{int l,r,w;} qr[MM];
vector<ll> bit;
vector<int> queries[MM];

void update(int x,int val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

ll get(int x)
{
    ll res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void updatequery(int l,int r,int val)
{
    update(l,val);
    update(r+1,-val);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    bit.resize(q + 7);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].w;
    }
    for(int i = 1;i <= n;i++) {
        L[i] = 1, R[i] = q; ans[i] = -1;
    }
    while(1) {
        bool ok = 1;
        for(int i = 1;i <= n;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            queries[ (L[i] + R[i]) / 2 ].push_back(i);
        }
        if(ok) break;
        for(int mid = 1;mid <= q;mid++) {
            updatequery(qr[mid].l, qr[mid].r, qr[mid].w);

            for(auto id: queries[mid]) {
                ll w = get(id);
                if(w >= a[id]) {
                    ans[id] = mid;
                    R[id] = mid - 1;
                }
                else L[id] = mid + 1;
            }
            queries[mid].clear();
        }
        fill(bit.begin(),bit.end(),0);
    }
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    return 0;
}