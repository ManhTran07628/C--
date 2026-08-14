#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2207 + 7;
const int MOD = 998244353;
ll dp[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "countpath"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    dp[0][0] = 1;
    for(int i = 1;i < MM;i++)
        for(int j = 1;j < MM;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1];
            dp[i][j] %= MOD;
        }
    int t; cin >> t;
    while(t--) {
        int r,c; cin >> r >> c;
        cout << dp[r][c] << ' ';
    }
    return 0;
}