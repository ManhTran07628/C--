#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int w,h,n,dp[607][607];
// dp[i][j] : so o trong it nhat khi cat ra thanh hcn i*j
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> h >> n;
    for(int i = 1;i <= w;i++) {
        for(int j = 1;j <= h;j++) {
            dp[i][j] = i*j;
        }
    }
    for(int i = 1;i <= n;i++) {
        int u,v;
        cin >> u >> v;
        dp[u][v] = 0;
    }
    for(int i = 1;i <= w;i++) {
        for(int j = 1;j <= h;j++) {
            if(!dp[i][j]) continue;
            for(int x = 1;x <= i;x++) {
                dp[i][j] = min(dp[i][j],dp[x][j]+dp[i-x][j]);
            }
            for(int x = 1;x <= j;x++) {
                dp[i][j] = min(dp[i][j],dp[i][x]+dp[i][j-x]);
            }
        }
    }
    cout << dp[w][h];
    return 0;
}