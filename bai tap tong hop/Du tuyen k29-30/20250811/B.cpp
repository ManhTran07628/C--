#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int dp[101][101],a[101][101],n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            cin >> a[i][j]; 
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(ans,dp[n][i]);
    cout << ans;
    return 0;
}