#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,m,k;
ll ps[MM][MM],a[MM][MM],p[MM];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rd(ll l,ll r)
{
    return rng() % (r - l + 1) + l;
}

ll get(int X1,int Y1,int X2,int Y2)
{
    return ps[X2][Y2] ^ ps[X1 - 1][Y2] ^ ps[X2][Y1 - 1] ^ ps[X1 - 1][Y1 - 1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin >> n >> m >> k; n++; m++;
    for(int i = 1;i <= k;i++) {
        int x,y,u,v; cin >> x >> y >> u >> v;
        ll val = rd(1,1e18);
        a[x + 1][y + 1] ^= val;
        a[u + 1][v + 1] ^= val;
        // cout << rd(1,1e18) << '\n';
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ps[i][j] = ps[i-1][j] ^ ps[i][j-1] ^ ps[i-1][j-1] ^ a[i][j];
        }
    }
    
    map<ll,ll> mp;
    ll res = 0;
    for(int x1 = 1;x1 <= n;x1++) {
        for(int x2 = x1 + 1;x2 <= n;x2++) {

            for(int j = 1;j <= m;j++) {
                p[j] = p[j-1] ^ get(x1,j,x2,j);
            }
            // mp[0] = 1;  //
            for(int j = 1;j <= m;j++) {
                res += mp[ p[j] ];
                mp[ p[j-1] ]++;  

            }

            mp.clear();

        }
    }
    cout << res;

    return 0;
}
