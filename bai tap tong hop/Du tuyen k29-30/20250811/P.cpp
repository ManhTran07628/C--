#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll dp[MM][2],c[MM],n;
string s[MM],rs[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= n;i++) {
        cin >> s[i];
        string t = s[i];
        reverse(t.begin(),t.end());
        rs[i] = t;
    }
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dp[i][1] = oo;
    }
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1;i <= n;i++) {
        if(s[i] >= s[i-1]) dp[i][0] = dp[i-1][0];
        if(s[i] >= rs[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(rs[i] >= s[i-1]) dp[i][1] = dp[i-1][0] + c[i];
        if(rs[i] >= rs[i-1]) dp[i][1] = min(dp[i][1],dp[i-1][1] + c[i]);
    }
    ll ans = min(dp[n][0],dp[n][1]);
    cout << (ans < oo ? ans:-1);
    return 0;
}