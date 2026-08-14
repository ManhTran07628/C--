#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
int n,dp[1 << 16][17],s[17],k;
// dp[mask][last] so cach sap xep cac con bo trong trang thai mask
// va ket thuc la con bo o vi tri last
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        cin >> s[i];
    }
    for(int i = 0;i < n;i++) {
        dp[1 << i][i] = 1;
    }
    for(int mask = 1;mask < (1 << n);mask++) {
        for(int last = 0;last < n;last++) {
            if(mask >> last & 1) {
                int prev_mask = mask ^ (1 << last);
                for(int prev = 0;prev < n;prev++) {
                    if((prev_mask >> prev & 1) && abs(s[last] - s[prev]) > k) {
                        dp[mask][last] = (dp[mask][last] + dp[prev_mask][prev]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++) ans = (ans + dp[(1<<n)-1][i]);
    cout << ans;
    return 0;
}