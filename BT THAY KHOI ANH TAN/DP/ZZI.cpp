#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[2005][2005];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string t = s;
    reverse(t.begin(),t.end());
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][n];
    return 0;
}