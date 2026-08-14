#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],t,n,x;
int dp[4][MAXN];

void solve()
{
    int ans = 0;
    dp[1][1] = a[1];
    dp[2][1] = a[1]*x;
    dp[3][1] = -1e18;
    for(int i = 2;i <= n;i++) {
        dp[1][i] = max(dp[1][i-1]+a[i],a[i]);
        dp[2][i] = max({dp[2][i-1]+a[i]*x,dp[1][i-1]+a[i]*x,a[i]*x});
        dp[3][i] = max({dp[3][i-1]+a[i],dp[2][i-1]+a[i],a[i]});
    }
    for(int i = 1;i <= n;i++) {
        ans = max({ans,dp[1][i],dp[2][i],dp[3][i]});
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}