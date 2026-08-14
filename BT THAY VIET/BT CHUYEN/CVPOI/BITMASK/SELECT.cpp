#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e4+7;
ll n,a[6][MM];
ll dp[MM][1 << 4];
ll sum[MM][1 << 4];
vector<int> valid[1 << 4];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    int m = 4;

    for(int mask = 0;mask < (1 << m);mask++) {
        for(int pmask = 0;pmask < (1 << m);pmask++) {
            
            if( pmask & (pmask >> 1) ) continue;
            
            if( (mask & pmask) == 0) valid[mask].push_back(pmask);
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int mask = 0;mask < (1 << m);mask++) {

            for(int j = 0;j < m;j++)
                if(mask >> j & 1) sum[i][mask] += a[j + 1][i];


        }
    }

    // for(int i = 1;i < (1 << m);i++) {
    //     bitset<4> xz = i;
    //     cout << xz << ' ';
    //     for(auto x:valid[i]) {
    //         bitset<4> xx = x;
    //         cout << xx << ' ';
    //     }
    //     cout << '\n';
    // }
    

    for(int i = 1;i <= n;i++) {
        ll ans = 0;
        for(int mask = 0;mask < (1 << m);mask++) {

            dp[i][mask] = dp[i-1][mask];

            if(mask & (mask >> 1)) continue;

            // bitset<4> xz = mask;
            // cout << xz << '\n';

            for(auto pmask : valid[mask]) {
                dp[i][mask] = max(dp[i][mask],dp[i-1][pmask] + sum[i][mask]);
            }
            ans = max(ans,dp[i][mask]);

        }
        // cout << ans << ' ';
    }

    ll res = 0;
    for(int i = 0;i < (1 << m);i++) res = max(res,dp[n][i]);
    cout << res;
    return 0;
}