#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[1001][1001],dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "robot"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        dp[1][i] = a[1][i] + dp[1][i-1];
    }
    for(int i = 2;i <= m;i++) {
        dp[i][1] = dp[i-1][1] + a[i][1];
        for(int j = 2;j <= n;j++) {
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[m][n];
    return 0;
}