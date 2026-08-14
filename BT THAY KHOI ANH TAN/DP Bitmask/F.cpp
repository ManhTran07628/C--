#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 17;
int n;
ll a[MM][MM],dp[1 << 16],f[1 << 16];

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
    for(int mask = 0;mask < (1 << n);mask++) {
        // dp[mask] = -oo;
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) 
                for(int j = i+1;j < n;j++) 
                    if(mask >> j & 1) 
                        f[mask] += a[i][j];

        }
    }
    dp[0] = 0;
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int submask = mask;submask > 0;submask = (submask-1) & mask) {
            dp[mask] = max(dp[mask],dp[mask ^ submask] + f[submask]);
        }
    }
    cout << dp[(1 << n)-1];
    return 0;
}