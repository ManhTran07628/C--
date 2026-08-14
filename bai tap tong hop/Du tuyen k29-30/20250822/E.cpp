#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
ll n,p,k;
ll dp[MM][1 << 7];

struct Dl{
    ll a;
    ll s[8];
} a[MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].a;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < p;j++) {
            cin >> a[i].s[j];
        }
    }
    sort(a+1,a+n+1, [](Dl &a, Dl &b) {
        return a.a > b.a;
    });
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int mask = 0;mask < (1 << p);mask++) {
            
            if(i - 1 - __builtin_popcount(mask) < k) {
                if(dp[i-1][mask] != -1)
                    dp[i][mask] = dp[i-1][mask] + a[i].a;
            }
            else {
                if(dp[i-1][mask] != -1)
					dp[i][mask] = dp[i-1][mask];
            }
            for(int j = 0;j < p;j++) {
                int prev_mask = mask ^ (1 << j);
                if((mask >> j & 1) && dp[i-1][prev_mask] != -1) {
                    dp[i][mask] = max(dp[i][mask],dp[i-1][prev_mask] + a[i].s[j]);
                }
            }
        }
    }
    cout << dp[n][(1 << p)-1];
    return 0;
}