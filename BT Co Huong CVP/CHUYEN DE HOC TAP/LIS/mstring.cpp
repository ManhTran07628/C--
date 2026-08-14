#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll dp[2001][2001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s,t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1;i <= s.size() - 1;i++)
        for(int j = 1;j <= t.size() - 1;j++) 
            dp[i][j] = oo;

    dp[0][0] = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(s[i] != t[j]) dp[i][j] = min(dp[i][j],dp[i-1][j-1] + 1);
            else dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
        }
    cout << dp[n][m];
    return 0;
}