#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN];
pair<int,int> k[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> k[i].fi >> k[i].se;
    }
    sort(k+1,k+n+1);
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;
        for(int j = i-1;j >= 1;j--) {
            if(k[i].fi >= k[j].se) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}