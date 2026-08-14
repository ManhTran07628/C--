#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,q;
ll a[MM],b[MM];
struct QR{int l,r,x,y;} qr[MM];

ll bitF[MM],bitmul[MM];

void update(int x,ll val,ll bit[])
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

ll get(int x,ll bit[])
{
    ll res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void update_range(ll l,ll r,ll x,ll y)
{
    ll F = x - l * y;
    update(l,F,bitF);
    update(r+1,-F,bitF);

    update(l,y,bitmul);
    update(r+1,-y,bitmul);
}

ll getpos(ll i)
{
    return get(i,bitF) + i * get(i,bitmul);
}

int ans[MM],L[MM],R[MM];
vector<int> queries[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= q;i++) cin >> qr[i].l >> qr[i].r >> qr[i].x >> qr[i].y;    
    for(int i = 1;i <= n;i++) {
        ans[i] = -1; L[i] = 1, R[i] = q;
        if(a[i] >= b[i]) {
            ans[i] = 0;
            L[i] = q + 1;
        }
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
            ll l = qr[mid].l, r = qr[mid].r, x = qr[mid].x, y = qr[mid].y;
            update_range(l,r,x,y);
            for(auto id:queries[mid]) {
                ll val = getpos(id);
                if(val + a[id] >= b[id]) {
                    ans[id] = mid;
                    R[id] = mid - 1;
                }
                else L[id] = mid + 1;
            }
            queries[mid].clear();
        }
        for(int i = 1;i <= n;i++) {
            bitF[i] = bitmul[i] = 0;
        }
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    return 0;
}