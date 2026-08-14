#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 100 + 7;
ll dp[MM][MM];

void solve(int n,int m)
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) 
            dp[i][j] = oo;
    
    
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {

            if(i == j) dp[i][j] = 0;

            for(int k = 1;k < i;k++) {
                dp[i][j] = min(dp[i][j],dp[i - k][j] + dp[k][j] + 1);
            }

            for(int k = 1;k < j;k++)
                dp[i][j] = min(dp[i][j],dp[i][j - k] + dp[i][k] + 1);

        }
    cout << dp[n][m] + 1 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin >> n >> m) {
        solve(n,m);
    }
    return 0;
}