#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
int n,m,a[MM];

ll bit[MM];

void update(int x,ll val)
{
    for(;x <= n;x += (x & -x)) {
        bit[x] = ((bit[x] + val) % MOD + MOD) % MOD;
    }
}

ll get(int x)
{
    ll res = 0;
    for(;x > 0;x -= (x & -x)) {
        res = ((res + bit[x]) % MOD + MOD) % MOD; 
    }
    return res;
}

ll get_range(int l,int r)
{
    return ((get(r) - get(l - 1)) % MOD + MOD) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        update(i,a[i]);
    }
    while(m--) {
        string type; cin >> type;
        if(type == "INC") {
            ll u,x; cin >> u >> x;
            update(u,x);
        }
        else {
            int l,r; cin >> l >> r;
            cout << get_range(l,r) << '\n';
        }
    }
    return 0;
}