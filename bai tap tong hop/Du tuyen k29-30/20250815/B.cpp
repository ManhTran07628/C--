#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e3+7;
ll dp[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    int n = s.size(),m = t.size();
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            dp[i][j] = oo;
        }
    }
    dp[0][0] = 0;
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            if(i > 0) dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            if(j > 0) dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            if(i > 0 && j > 0) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(s[i-1] != t[j-1]));
        }
    }
    cout << dp[n][m];
    return 0;
}