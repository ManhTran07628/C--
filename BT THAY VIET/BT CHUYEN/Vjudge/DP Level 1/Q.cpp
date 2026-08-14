#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 17;
int a[MM][MM],dp[1 << 16];
void solve()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
    for(int mask = 1;mask < (1 << n);mask++) {
        int prev_bit = -1;
        for(int i = 0;i < n;i++) {
            if((mask >> i) & 1) {
                if(prev_bit != -1) {
                    int prev_mask = mask ^ (1 << i);
                    dp[mask] = max(dp[prev_mask]+a[prev_bit][i],dp[mask]);
                }
                prev_bit = i;
            }
        }
    }
    for(int i = 0;i < (1 << n);i++) cout << i << ' ' << dp[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    // int t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    return 0;
}