#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e4+7;
ll n,a[9][MM],dp[1 << 8][MM],Rowsum[1 << 8][MM];
// dp[mask][j] tong gia tri lon nhat tinh tu 1 -> j-1
// va dang xet trang thai mask o cot thu j
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= 8;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    vector<ll> comp[1 << 8],valid;
    for(int mask = 0;mask < (1 << 8);mask++) {
        if(mask & (mask << 1)) continue;
        for(int prev_mask = 1;prev_mask < (1 << 8);prev_mask++) {
            if(prev_mask & (prev_mask << 1)) continue;
            if(!(mask & prev_mask)) 
                comp[mask].push_back(prev_mask);
        }
        valid.push_back(mask);
    }
    for(int j = 1;j <= n;j++) {
        for(auto mask:valid) {
            ll sum = 0;
            for(int i = 0;i < 8;i++){
                if(mask >> i & 1) 
                    sum += a[i+1][j];
            }
            Rowsum[mask][j] = sum;
        }
    }
    ll ans = 0;
    for(int j = 1;j <= n;j++) {
        for(int mask = 0;mask < (1 << 8);mask++) {
            if(mask & (mask << 1)) continue;
            for(auto prev:comp[mask]) {
                dp[mask][j] = max(dp[mask][j],dp[prev][j-1]+Rowsum[prev][j]);
                ans = max(ans,dp[mask][j]);
            }
        }
    }
    cout << ans;
    return 0;
}