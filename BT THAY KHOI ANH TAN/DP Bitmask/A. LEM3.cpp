#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,c[17][17],dp[1 << 17][17];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 1;i < (1 << n);i++) {
        for(int j = 0;j < n;j++) {
            dp[i][j] = oo;
        }
    }
    // dp[mask][k] : chi phi be nhat de di qua cac thanh pho nam trong tap mask va ket thuc o k
    for(int i = 0;i < n;i++) dp[1 << i][i] = 0;
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int prev_mask = mask & ~(1 << i);
                for(int k = 0;k < n;k++) 
                    dp[mask][i] = min(dp[mask][i],dp[prev_mask][k]+c[i+1][k+1]);
            }
        }
    }
    int ans = oo;   
    for(int i = 0;i < n;i++) ans = min(ans,dp[(1<<n)-1][i]);
    cout << ans;
    return 0;
}