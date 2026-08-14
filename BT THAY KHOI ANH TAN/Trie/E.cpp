#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e3+7;
ll dp[MM][MM],f[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        dp[i][i] = 1;
        dp[i+1][i] = 1;
        f[i] = oo;
    }


    for(int len = 2;len <= n;len++) {
        for(int i = 1;i + len - 1 <= n;i++) {
            int l = i,r = i + len - 1;
            while(1 <= l && r <= n) {
                if(dp[l+1][r-1] && s[l] == s[r]) 
                    dp[l][r] = 1;
                l--;
                r++;
            }
        }
    }


    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            if(dp[j][i])
                f[i] = min(f[i],f[j-1] + 1);
        }
    }
    cout << f[n];
    return 0;
}