#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 50 + 7;
ll dp[MM][MM];
map<int,int> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; n++;
    dp[1][1] = 1;
    

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {

            if(j < i) continue;
            // cout << i << ' ' << j << '\n';
            dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];

        }
    }
    cout << dp[n][n];
    return 0;
}