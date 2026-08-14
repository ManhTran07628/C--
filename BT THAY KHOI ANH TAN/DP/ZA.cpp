#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int c[MAXN][4],dp[MAXN][4];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    for(int i = 1;i <= m;i++) {
        cin >> c[i][1] >> c[i][2] >> c[i][3];
    }
    dp[1][1] = c[1][1];
    dp[1][2] = c[1][2];
    dp[1][3] = c[1][3];
    for(int i = 2;i <= m;i++) {
        dp[i][1] = min(dp[i-1][2],dp[i-1][3])+c[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][3])+c[i][2];
        dp[i][3] = min(dp[i-1][1],dp[i-1][2])+c[i][3];
    }
    cout << min({dp[m][1],dp[m][2],dp[m][3]});
    return 0;
}