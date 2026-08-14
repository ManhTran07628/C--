#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 21;
int MOD = 1e9+7;
int n,a[MM][MM],dp[1 << 20][21];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    for(int mask = 1;mask < (1 << n);mask++) {
        int sz = __builtin_popcount(mask);
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1 && a[sz-1][i]) {
                int prev_mask = mask ^ (1 << i);
                dp[mask][sz] = (dp[mask][sz] + dp[prev_mask][sz-1]) % MOD;
            }
        }
    }
    cout << dp[(1 << n)-1][n];
    return 0;
}