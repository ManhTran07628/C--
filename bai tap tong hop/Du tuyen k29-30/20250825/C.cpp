#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5000+7;
int dp[MM][MM],ans[MM][MM],q,n;
string s;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> q;
    n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        dp[i][i] = 1;
    }
    for(int i = 1;i < n;i++) {
        if(s[i] == s[i+1]) dp[i][i+1] = 1;
    }
    for(int len = 3;len <= n;len++) {
        for(int L = 1;L <= n-len+1;L++) {
            int R = L+len-1;
            if(s[L] == s[R] && dp[L+1][R-1]) dp[L][R] = 1;
        }
    }
    for(int len = 1;len <= n;len++) {
        for(int L = 1;L <= n-len+1;L++) {
            int R = L+len-1;
            ans[L][R] = ans[L+1][R] + ans[L][R-1] - ans[L+1][R-1] + dp[L][R];
        }
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << ans[l][r] << '\n';
    }
    return 0;
}