#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,dp[MM][2],a[MM],b[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 2;i <= n;i++) {
        dp[i][0] = min(dp[i-1][0]+abs(a[i]-a[i-1]),dp[i-1][1]+abs(a[i]-b[i-1]));
        dp[i][1] = min(dp[i-1][0]+abs(b[i]-a[i-1]),dp[i-1][1]+abs(b[i]-b[i-1]));
    }
    cout << min(dp[n][0],dp[n][1]);
    return 0;
}