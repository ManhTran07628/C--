#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 1e9+7;
ll dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1;i <= k;i++) dp[i] = dp[i-1] + 1;
    for(int i = k+1;i <= n;i++)
        dp[i] = (dp[i-k] + dp[i-1]) % MOD;
    cout << dp[n];
    return 0;
}