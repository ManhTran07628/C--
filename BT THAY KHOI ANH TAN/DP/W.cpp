#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[1001][1001],dp[1001][1001];
int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,w;
    cin >> h >> w;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            char c;
            cin >> c;
            if(c == '.') a[i][j] = 1;
        }
    }
    dp[1][1] = 1;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            if(a[i][j] == 0) dp[i][j] = 0;
            else dp[i][j] += (dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout << dp[h][w];
    return 0;
}