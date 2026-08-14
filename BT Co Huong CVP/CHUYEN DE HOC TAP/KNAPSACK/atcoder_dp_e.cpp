#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
ll n,W,w[MM],v[MM];
ll dp[101][MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> W;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 0;i <= n;i++)
        for(int j = 1;j < MM;j++)
            dp[i][j] = oo;

    dp[0][0] = 0;
    for(int i = 1;i <= n;i++)
        for(int j = MM - 1;j >= 1;j--) {
            dp[i][j] = dp[i-1][j];

            if(j >= v[i])   
                dp[i][j] = min(dp[i][j],dp[i-1][j - v[i]] + w[i]);
        }
    
    ll res = 0;
    for(int j = 1;j < W;j++) {
        if(dp[n][j] <= W) res = j;
        // cout << j << ' ' << dp[n][j] << '\n';
    }
    cout << res;
    return 0;   
}