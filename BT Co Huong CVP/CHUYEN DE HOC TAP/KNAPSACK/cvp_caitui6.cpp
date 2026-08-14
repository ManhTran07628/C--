#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
ll n,W,C,w[MM],v[MM],c[MM];
vector<vector<ll>> dp;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> W >> C;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i] >> c[i];
    }
    dp.resize(W + 3);
    for(int i = 0;i <= W;i++) 
        dp[i].resize(C + 3);
    
    ll res = 0;
    for(int i = 1;i <= n;i++)
        for(int j = W;j >= w[i];j--)
            for(int k = C;k >= c[i];k--) {
                dp[j][k] = max(dp[j][k],dp[j - w[i]][k - c[i]] + v[i]);
                res = max(res,dp[j][k]);
            }

    cout << res;
    return 0;
}
