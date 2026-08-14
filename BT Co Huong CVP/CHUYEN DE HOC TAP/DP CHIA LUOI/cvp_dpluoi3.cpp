#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 500 + 7;
ll dp[MM][MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) 
            dp[i][j] = oo;
    
    dp[1][1] = 0;
    
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {

            for(int k = 1;k < i;k++) {
                dp[i][j] = min(dp[i][j],dp[i - k][j] + dp[k][j] + i * j);
            }
            
            for(int k = 1;k < j;k++)
                dp[i][j] = min(dp[i][j],dp[i][j - k] + dp[i][k] + i * j);
        }
    cout << dp[n][m] << '\n';
    return 0;
}