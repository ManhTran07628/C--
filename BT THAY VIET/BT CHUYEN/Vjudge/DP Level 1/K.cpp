O#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
ll dp[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    cin >> a >> b;
    for(int i = 1;i <= a;i++) {
        for(int j = 1;j <= b;j++) {
            if(i == j) dp[i][j] = 0;
            else {
                dp[i][j] = oo;
            }
            for(int x = 1;x < i;x++) {
                dp[i][j] = min(dp[i-x][j] + dp[x][j] + 1,dp[i][j]);
            }
            for(int y = 1;y < j;y++) {
                dp[i][j] = min(dp[i][j-y] + dp[i][y] + 1,dp[i][j]);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}