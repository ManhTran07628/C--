#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[105][105],dp[105][105];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) dp[1][i] = a[1][i];
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int temp = 1e9;
            if(j-1 > 0) temp = min(temp,dp[i-1][j-1]);
            if(j+1 <= n) temp = min(temp,dp[i-1][j+1]); 
            dp[i][j] = min(dp[i-1][j],temp)+a[i][j];
        }
    }
    int ans = 1e9;
    for(int i = 1;i <= n;i++) ans = min(ans,dp[n][i]);
    cout << ans;
    return 0;
}