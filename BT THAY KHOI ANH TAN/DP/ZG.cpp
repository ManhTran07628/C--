#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 101;
int w[MAXN],v[MAXN];
int dp[101][100001];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h;
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= h;j++) {
            dp[i][j] += dp[i-1][j];
            if(j >= w[i]) {
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i][j]);
            }
        }
    }
    cout << dp[n][h];
    return 0;
}