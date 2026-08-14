#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 998244353;
ll q,k,dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;
    cin >> q >> k;
    while(q--) {
        char c;
        ll u;
        cin >> c >> u;
        if(c == '+') {
            for(int i = k;i >= 1;i--) 
                if(i >= u) dp[i] = (dp[i] + dp[i-u]) % MOD;
        }
        else {
            for(int i = 1;i <= k;i++) {
                if(i >= u) dp[i] = (dp[i] - dp[i-u]) % MOD;
            }
        }
        cout << dp[k] << '\n';
    }
    return 0;
}