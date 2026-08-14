#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int dp[501][501];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    for(int i = 1;i <= a;i++) {
        for(int j = 1;j <= b;j++) {
            dp[i][j] = oo;
        }
    }
    for(int i = 1;i <= a;i++) {
        for(int j = 1;j <= b;j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1;k <= a;k++) {
                if(i >= k)
                    dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            for(int k = 1;k <= b;k++) {
                if(j >= k)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}