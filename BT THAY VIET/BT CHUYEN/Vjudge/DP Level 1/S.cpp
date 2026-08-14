#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll dp[55];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 2;
    for(int i = 3;i <= n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}