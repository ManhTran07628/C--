#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 501,MOD = 1e9+7;;
ll n,dp[MM][62626];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll s = n*(n+1)/2;
    if(s % 2 != 0) {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= s/2;j++) {
            dp[i][j] += dp[i-1][j]; 
            if(j >= i) 
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
        }
    }
    cout << dp[n][s/2] % MOD;
    return 0;
}