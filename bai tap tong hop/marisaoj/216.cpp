#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e4+7;
const int MOD = 1e9+7;
int n,m;
ll dp[1 << 5][MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m;
    // dp[0][0] = 1;
    for(int mask = 0;mask < (1 << m);mask++) dp[mask][1] = 1;
    for(int j = 2;j <= n;j++) {
        for(int mask = 0;mask < (1 << m);mask++) {

            for(int submask = mask;submask > 0;submask = (submask-1) & mask) {
                dp[mask][j] = (dp[mask][j] + dp[submask][j-1]) % MOD;
            }

        }
    }
    ll ans = 0;
    for(int mask = 0;mask < (1 << m);mask++) ans = (ans + dp[mask][n]) % MOD;
    cout << ans;
    return 0;
}