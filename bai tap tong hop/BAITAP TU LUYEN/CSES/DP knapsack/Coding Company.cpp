#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int t[105],dp[105][5001];
// dp[i][j]: so cach tao ra chenh lech trinh do la j khi chon lap trinh vien
// thu i vao team nao do
int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> t[i];
    }
    dp[0][0] = 1;
    sort(t+1,t+n+1);
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= x;j++) {
            dp[i][j] += dp[i-1][j];
            for(int k = i;k >= 1;k--) {
                if(t[i] - t[k] == j) {
                    dp[i][j] = (dp[i][j] + dp[k][j]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= x;i++) {
        ans = (ans+dp[n][i])%MOD;
        cout << dp[n][i] << ' ';
    }
    cout << ans;
    return 0;
}