#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],b[MAXN];
int dp[1001][4097];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    k *= 1024;
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= n;j++) {
            dp[j][i] += dp[j-1][i];
            if(i >= a[j]) {
                dp[j][i] = max(dp[j][i-a[j]]+b[j],dp[j][i]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}