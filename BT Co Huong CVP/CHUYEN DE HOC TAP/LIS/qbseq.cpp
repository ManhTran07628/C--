#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,a[MM],k;
int dp[MM][51];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] %= k;
    }

    for(int i = 0;i <= n;i++)
        for(int j = 0;j < k;j++) dp[i][j] = -oo;

    int res = 0;
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) {

        for(int d = 0;d < k;d++) {
            int mod = ((d - a[i]) % k + k) % k;
            if(dp[i-1][mod] != -oo)
                dp[i][d] = max(dp[i][d],dp[i-1][mod] + 1);
            dp[i][d] = max(dp[i][d],dp[i-1][d]);
        }

        // for(int d = 0;d < 50;d++)
        res = max(res,dp[i][0]);
    }
    cout << res;
    return 0;
}
