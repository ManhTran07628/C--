#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2207 + 7;
int r,c,a[MM][MM];
ll dp[MM][MM]; 

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "haitumtp"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> r >> c;
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++) {
            cin >> a[i][j];
        }
        
    for(int i = 0;i < r;i++)
        for(int j = 0;j <= c;j++)
            dp[i][j] = oo;

    for(int i = 0;i < r;i++)
        dp[i][0] = 0;

    for(int j = 0;j < c;j++)
        for(ll i = 0;i < r;i++) {
            int x1 = i * i % r, x2 = i * i * i % r;
            int x3 = i * i * i * i % r;
            dp[x1][j+1] = min(dp[x1][j+1],dp[i][j] + a[i][j]);
            dp[x2][j+1] = min(dp[x2][j+1],dp[i][j] + a[i][j]);
            dp[x3][j+1] = min(dp[x3][j+1],dp[i][j] + a[i][j]);
        }

    
    ll res = oo;
    for(int i = 0;i < r;i++) res = min(res,dp[i][c]);
    cout << res;
    return 0;
}