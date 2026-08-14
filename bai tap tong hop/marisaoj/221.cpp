#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
ll n,dp[1 << 20],a[21][21];
// dp[mask] : suc manh lon nhat khi ket hop cac cay nam
// trong thai mask
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll m = n*2;
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < (1 << m);i++) {
        dp[i] = -oo;
    }
    dp[0] = 0;
    for(int mask = 0;mask < (1 << m);mask++) {
        for(int i = 0;i < m;i++) {
            if(mask >> i & 1) continue;
            int next_mask = mask | (1 << i);
            for(int j = 0;j < m;j++) {
                if(mask >> j & 1 || i == j) continue;
                int new_mask = next_mask | (1 << j);
                dp[new_mask] = max(dp[new_mask],dp[mask] + a[i][j]);
            }
        }
    }
    cout << dp[(1 << m)-1];
    return 0;
}