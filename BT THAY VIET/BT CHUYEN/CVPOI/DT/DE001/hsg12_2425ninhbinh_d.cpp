#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 20 + 7;
ll dp[1 << 20];
ll n,k,c[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> c[i][j];

            
    for(int mask = 0;mask < (1 << n);mask++) dp[mask] = oo;
    dp[(1 << n) - 1] = 0;

    for(int mask = (1 << n) - 1;mask >= 1;mask--) {
        for(int u = 0;u < n;u++) {

            if(!(mask >> u & 1)) {
                int pmask = mask | (1 << u);

                for(int v = 0;v < n;v++) 
                    if(mask >> v & 1) {
                        dp[mask] = min(dp[mask],dp[pmask] + c[u][v]);
                    }

            }

        }
    }

    ll res = oo;
    for(int mask = 1;mask < (1 << n);mask++)
        if(__builtin_popcount(mask) == k) 
            res = min(res,dp[mask]);
    cout << res;
    return 0;
}