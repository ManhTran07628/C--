#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MOD = 1e9+7;
ll n,m,dp[1 << 10][201];
vector<ll> comp[1 << 10];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int mask = 0;mask < (1 << n);mask++) {
        if(mask & (mask >> 1)) continue;
        for(int pmask = 0;pmask < (1 << n);pmask++) {
            if(pmask & (pmask >> 1)) continue;
            bool ok = 1;
            for(int i = 0;i < n;i++) {
                if((mask >> i & 1) && (pmask >> i & 1)) ok = 0;
            }
            if(ok) comp[mask].push_back(pmask);
        }
    }
    bitset<4> a = 0;
    dp[0][0] = 1;
    for(int j = 1;j <= m;j++) {
        for(int mask = 0;mask < (1 << n);mask++) {
            if(mask & (mask >> 1)) continue;
            for(auto pmask:comp[mask]) {
                dp[mask][j] = (dp[mask][j] + dp[pmask][j-1]) % MOD;
            }
        }
    }
    ll ans = 0;
    for(int mask = 0;mask < (1 << n);mask++) {
        if(mask & (mask >> 1)) continue;
        ans = (ans + dp[mask][m]) % MOD;
    }
    cout << ans;
    return 0;
}