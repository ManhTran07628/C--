#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
ll n,dp[1 << 20][21],a[21][21];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            dp[mask][i] = oo;
        }
    }
    // for(int i = 0;i < n;i++) {
    //     dp[1 << i][i] = 0;
    // }
    dp[1 << 0][0] = 0;
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int prev_mask = mask ^ (1 << i);
                for(int j = 0;j < n;j++) {
                    if(prev_mask >> j & 1) {
                        dp[mask][i] = min(dp[mask][i],dp[prev_mask][j] + a[j][i]);
                    }
                }
            }
        }
    }
    ll ans = oo;
    for(int i = 1;i < n;i++) {
        ans = min(ans,dp[(1 << n)-1][i] + a[i][0]);
        // cout << dp[(1 << n)-1][i] + a[i][0] << ' ';
    }
    cout << ans;
    return 0;
}