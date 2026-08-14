#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
ll n,t,dp[MM][2],a[MM];
// dp[i][k] : so diem can dung it nhat khi tieu diet den boss thu i
// voi k la 0/1 tuong ung voi luot friend hoac luot cua ban
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(i >= 2)
            dp[i][0] = dp[i][1] = oo;
    }
    dp[1][0] = dp[1][1] = 0;
    if(a[1]) dp[1][1] = dp[1][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= 1;j++) {
            dp[i+1][1-j] = min(dp[i+1][1-j],dp[i][j]+a[i+1]*j);
            dp[i+2][1-j] = min(dp[i+2][1-j],dp[i][j]+(a[i+2]+a[i+1])*j);
        }
    }
    cout << min(dp[n][0],dp[n][1]) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}