#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int h[1005],s[1005],dp[MAXN];
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> s[i];
 
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = x;j >= h[i];j--) {
            dp[j] = max(dp[j],dp[j-h[i]]+s[i]);
            ans = max(ans,dp[j]);
        }
    }
    cout << ans;
    return 0;
}