#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
int dp[MM][MM],n,a[MM],b[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "nocross"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];


    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(abs(a[i]-b[j]) <= 4) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }   
    }
    cout << dp[n][n];
    return 0;
}   