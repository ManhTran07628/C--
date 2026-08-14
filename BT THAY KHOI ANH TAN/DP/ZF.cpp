#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[11][10001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 1;i <= a[1];i++) dp[1][i] = 1;

    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= a[i];j++) {
            for(int k = s;k >= j;k--) {
                dp[i][k] += dp[i-1][k-j];
            }
        }
    }
    int ans = 1;
    for(int i = 1;i <= s;i++) {
        if(dp[n][i] > dp[n][ans]) ans = i;
    }
    cout << ans;
    return 0;
}