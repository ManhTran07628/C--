#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int t,a,b,dp[MM][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "feast"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t >> a >> b;
    dp[0][0] = 1;
    for(int i = 0;i <= t;i++) {
        if(i+a <= t && dp[i][0]) dp[i+a][0] = 1;
        if(i+b <= t && dp[i][0]) dp[i+b][0] = 1;
        if(dp[i][0]) dp[i/2][1] = 1;
    }
    for(int i = 0;i <= t;i++) {
        if(i+a <= t && dp[i][1]) dp[i+a][1] = 1;
        if(i+b <= t && dp[i][1]) dp[i+b][1] = 1;
    }

    int ans = 0;
    for(int i = 1;i <= t;i++) {
        if(dp[i][0] || dp[i][1]) ans = i;
    }
    cout << ans;
    return 0;
}