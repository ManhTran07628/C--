#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[1001][1001],dp[1001][1001];
int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '.' ? 1 : 0);
        }
    }
    dp[1][1] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j])
                dp[i][j] += (dp[i-1][j]+dp[i][j-1])%MOD;
            else dp[i][j] = 0;
        }
    }
    cout << dp[n][n];
    return 0;
}