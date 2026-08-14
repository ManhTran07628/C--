#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
ll n,x,w[MM];
pair<ll,ll> dp[1 << 20];
// first - cnt    second - cur weight
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0;i < n;i++) {
        cin >> w[i];
    }
    for(int i = 0;i < (1 << n);i++) 
        dp[i] = {oo,oo};
    dp[0] = {1,0};
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int prev_mask = mask ^ (1 << i);
                ll cnt = dp[prev_mask].first;
                ll cur_w = dp[prev_mask].second;
                if(cur_w + w[i] <= x) dp[mask] = min(dp[mask],{cnt, cur_w+w[i]});
                else dp[mask] = min(dp[mask],{cnt+1,w[i]});
            }
        }
    } 
    cout << dp[(1 << n) - 1].first;
    return 0;
}