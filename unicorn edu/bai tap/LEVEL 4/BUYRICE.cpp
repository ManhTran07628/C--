#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 100+7;
const int lim = 55000;
int n,h,p[MM],c[MM];
int dp[MM][lim];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        cin >> p[i] >> c[i];
    }
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= lim;j++)
            dp[i][j] = oo;

    for(int i = 0;i <= n;i++) dp[i][0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= lim;j++) {
            dp[i][j] = min(dp[i][j],dp[i-1][j]);

            if(j >= p[i]) 
                dp[i][j] = min(dp[i][j],dp[i][j - p[i]] + c[i]);

        }
    }
    int res = oo; 
    for(int i = h;i <= lim;i++) {
        if(dp[n][i]) res = min(res,dp[n][i]);
    }
    cout << res;
    return 0;
}