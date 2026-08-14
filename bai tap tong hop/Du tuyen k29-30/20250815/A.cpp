#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int MOD = 1e9+7;
int dp[MM][101],x[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> x[i];
    if(x[1] == 0) {
        for(int i = 1;i <= m;i++) {
            dp[1][i] = 1;
        }
    }
    else dp[1][x[1]] = 1;
    for(int i = 2;i <= n;i++) {
        if(!x[i]) {
            for(int j = 1;j <= m;j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
        else {
            dp[i][x[i]] = dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1];
            dp[i][x[i]] %= MOD;
        }
    }
    int ans = 0;
    if(x[n] == 0) {
        for(int i = 1;i <= m;i++)   
            ans += dp[n][i];
        cout << ans % MOD;
    }
    else cout << dp[n][x[n]]%MOD;
    return 0;
}