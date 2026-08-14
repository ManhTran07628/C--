#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[501][501],dp[501][501];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        dp[i][1] = a[i][1];
    }
    for(int j = 2;j <= m;j++) {
        for(int i = 1;i <= n;i++) {
            int temp = -1e9;
            if(i-1 > 0) temp = max(temp,dp[i-1][j-1]);
            if(i+1 <= n) temp = max(temp,dp[i+1][j-1]);
            dp[i][j] = max(temp,dp[i][j-1])+a[i][j];
        }
    }    
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(ans,dp[i][m]);
    cout << ans;
    return 0;
}