#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[501][70000];
int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s = n*(n+1)/2;
    if(s%2 != 0) {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= s/2;j++) {
            dp[i][j] += dp[i-1][j];
            if(j >= i) 
                dp[i][j] = (dp[i-1][j-i]+dp[i][j])%MOD;
        }
    }
    cout << dp[n][s/2];
    return 0;   
}