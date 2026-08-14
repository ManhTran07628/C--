#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,h,w[107],v[107],dp[107][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= h;j++) {
            dp[i][j] += dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout << dp[n][h];
    return 0;
}