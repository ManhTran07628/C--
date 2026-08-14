#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[101][100010];
int h[101],v[101];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin >> n >> w;
    for(int i = 1;i <= n;i++) {
        cin >> h[i] >> v[i];
    }
    for(int i = 1;i <= 100005;i++) dp[0][i] = 1e18;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 100005;j++) {
            dp[i][j] += dp[i-1][j];
            if(j >= v[i]) 
                dp[i][j] = min(dp[i-1][j-v[i]]+h[i],dp[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1;i <= 100001;i++) {
        if(dp[n][i] <= w) {
            ans = max(ans,i);
        }
    }
    cout << ans;
    return 0;
}