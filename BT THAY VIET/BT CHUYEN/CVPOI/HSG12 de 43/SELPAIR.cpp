#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll n,a[1 << 20],b[1 << 20];
pair<ll,ll> dp[1 << 20];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < (1 << n);i++) cin >> a[i] >> b[i];

    for(int i = 0;i < (1 << n);i++) dp[i] = {b[i],i};

    for(int mask = 0;mask < (1 << n);mask++)
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                if(dp[mask].fi < dp[mask ^ (1 << i)].fi) {
                    dp[mask] = dp[mask ^ (1 << i)];
                }
            }
        }

    ll res = 0,x = 0,y = 0;
    for(int i = 0;i < (1 << n);i++) {  
        ll j = i ^ ((1 << n) - 1);
        if(res < a[i] + dp[j].fi ) {
            res = a[i] + dp[j].fi;
            x = i, y = dp[j].se;
        }
        // cout << i << ' ' << j << '\n';
    }
    cout << x << ' ' << y;
    return 0;
}
