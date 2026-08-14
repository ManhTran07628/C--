#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3007;
string s,t;
int dp[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    int n = s.size(),m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string res = " ";
    while(n > 0 && m > 0) {
        if(dp[n][m] == dp[n-1][m]) {
            n--;
        }
        else if(dp[n][m] == dp[n][m-1]) {
            m--;
        }
        else if(dp[n][m] == dp[n-1][m-1]+1) {
            res += s[n];
            n--;m--;
        }
    }
    reverse(res.begin(),res.end());
    cout << res;
    return 0;
}