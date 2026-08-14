#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN],dp[MAXN][101];
int n,k;
void sub123()
{
    int suf_max[MAXN],pre_min[MAXN];
    pre_min[0] = 1e18;
    for(int i = 1;i <= n;i++) 
        pre_min[i] = min(pre_min[i-1],a[i]);
    for(int i = n;i >= 1;i--)
        suf_max[i] = max(suf_max[i+1],a[i]);
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,suf_max[i+1]-pre_min[i]);
    }
    cout << ans << '\n';
}

void sub4()
{   // dp[i][j] : loi nhuan lon nhat khi thuc hien j thao tac den vi tri i
    int pre_max[MAXN];
    for(int i = 0;i <= k-1;i++) pre_max[i] = -1e18;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            dp[i][j] = max(dp[i-1][j],pre_max[j-1]+a[i]);
            // for(int d = 1;d <= i-1;d++) 
            //     dp[i][j] = max(dp[i][j],dp[d-1][j-1]+a[i]-a[d]);
        }
        for(int j = 0;j <= k-1;j++) {
            pre_max[j] = max(pre_max[j],dp[i-1][j]-a[i]);
        }
    }
    cout << dp[n][k];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(k == 1) sub123();
    else sub4();
    return 0;
}