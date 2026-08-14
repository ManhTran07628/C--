#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN+7],a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,ans = LLONG_MIN;
    cin >> n;
    fill(dp+1,dp+MAXN+1,LLONG_MIN);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    for(int i = 1;i <= n;i++) {
        dp[i] = max(dp[i-1]+a[i],a[i]);
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}