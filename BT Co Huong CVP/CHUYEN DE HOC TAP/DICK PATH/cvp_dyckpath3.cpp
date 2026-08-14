#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 50 + 7;
const int MOD = 1e9 + 7;
ll dp[MM][MM];
int mp[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k; 
    while(k--) {
        int x,y; cin >> x >> y;
        mp[x + 1][y + 1] = 1;
    }

    dp[n][1] = 1;
    for(int i = n;i >= 1;i--) {
        for(int j = 1;j <= n;j++) {
            if(n - i + 1 < j) continue;
            if(mp[i][j]) continue;
            // cout << i << ' ' << j << '\n';
            dp[i][j] = (dp[i][j] + dp[i+1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[1][n];
    return 0;
}