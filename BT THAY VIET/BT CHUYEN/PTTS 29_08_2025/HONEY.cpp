#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1000+7;
int n,a[MM][MM],m,maxrow[MM];
int dp[MM][MM][2];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    m = n*2-1;
    for(int i = 1;i <= m;i++) {
        if(i <= n) {
            for(int j = 1;j <= i+n-1;j++) {
                cin >> a[i][j];
                maxrow[i] = max(maxrow[i],a[i][j]);
            }
        }
        else {
            for(int j = 1;j <= m-(i-n);j++) {
                cin >> a[i][j];
                maxrow[i] = max(maxrow[i],a[i][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i+n-1;j++) {
            if(j == 1) {
                dp[i][j][0] = dp[i-1][j][0] + a[i][j];
                dp[i][j][1] = max(dp[i-1][j][0] + maxrow[i],dp[i-1][j][1] + a[i][j]);
            }
            else if(j == i+n-1) {
                dp[i][j][0] = dp[i-1][j-1][0] + a[i][j];
                dp[i][j][1] = max(dp[i-1][j-1][0] + maxrow[i],dp[i-1][j-1][1] + a[i][j]);
            }
            else {
                dp[i][j][0] = max(dp[i-1][j-1][0],dp[i-1][j][0]) + a[i][j];
                dp[i][j][1] = max({dp[i-1][j-1][0] + maxrow[i],dp[i-1][j][0] + maxrow[i],
                    dp[i-1][j-1][1] + a[i][j],dp[i-1][j][1] + a[i][j]});
            }
        }
    }
    for(int i = n+1;i <= m;i++) {
        for(int j = 1;j <= m-(i-n);j++) {
            dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j+1][0]) + a[i][j];
            dp[i][j][1] = max({dp[i-1][j][0] + maxrow[i],dp[i-1][j+1][0] + maxrow[i],
                    dp[i-1][j][1] + a[i][j],dp[i-1][j+1][1] + a[i][j]});
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max({ans,dp[m][i][0],dp[m][i][1]});
    }
    cout << ans;
    return 0;
}