#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 19;
int n,m,k,a[MM];
pair<int,int> ds[MM][MM];
ll dp[1 << 18][18];
// do thoa man lon nhat khi an cac mon trong trang thai mask
// va ket thuc la mon thu i
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < k;i++) {
        int x,y,c;
        cin >> x >> y >> c;
        ds[--x][--y] = {1,c};
    }
    for(int i = 0;i < n;i++) {
        dp[1 << i][i] = a[i];
    }
    for(int mask = 1;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int prev_mask = mask ^ (1 << i);
                for(int j = 0;j < n;j++) {
                    if(prev_mask >> j & 1) {
                        ll cost = dp[prev_mask][j]+a[i];
                        if(ds[j][i].fi) cost += ds[j][i].se;
                        dp[mask][i] = max(dp[mask][i],cost);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int mask = 1;mask < (1 << n);mask++) {
        if(__builtin_popcount(mask) == m)
            for(int i = 0;i < n;i++) {
                if(mask >> i & 1) {
                    ans = max(ans,dp[mask][i]);
                }
            }
    }
    cout << ans;
    return 0;
}