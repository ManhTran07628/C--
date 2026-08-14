#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 22;
const int MOD = 1e9+7;
int n,a[MM][MM];
ll dp[1 << 21];
vector<int> ds[MM];
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
    dp[0] = 1;
    for(int mask = 1;mask < (1 << n);mask++) {
        int k = __builtin_popcount(mask);
        for(int i = 0;i < n;i++) {
            if(a[k-1][i]) {
                dp[mask] += dp[mask ^ (1 << i)];
                dp[mask] %= MOD;
            }
        }
    }
    cout << dp[(1 << n)-1];
    return 0;
}