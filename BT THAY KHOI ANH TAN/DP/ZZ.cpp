#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[3001][3001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    int n = s.size(),m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i] == t[j]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][m];
    return 0;
}