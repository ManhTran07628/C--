#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
const int MOD = 1e9+7;
ll dp[1001][1001],a[MM][MM],n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            char c;
            cin >> c;
            if(c == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    if(a[1][1]) dp[1][1] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j]) dp[i][j] = (dp[i][j]+dp[i][j-1]+dp[i-1][j]) % MOD;
        }
    }
    cout << dp[n][n];
    return 0;
}