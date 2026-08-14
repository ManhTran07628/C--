#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[5005][5005];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,x;
    cin >> n >> k >> x;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        int d = lower_bound(a+1,a+n+1,a[i]-x)-a;
        for(int j = 1;j <= k;j++) {
            dp[i][j] = max(dp[i-1][j],dp[d-1][j-1]+i-d+1); 
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}