#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5;
int w[MAXN],v[MAXN],a[MAXN];
int dp[101][10001];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h;
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i] >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= h;j++) {
            dp[i][j] += dp[i-1][j];
            for(int k = 1;k <= a[i];k++) {
                if(j >= k*w[i]) 
                    dp[i][j] = max(dp[i-1][j-k*w[i]]+k*v[i],dp[i][j]);
            }
        }
    }
    cout << dp[n][h];
    return 0;
}