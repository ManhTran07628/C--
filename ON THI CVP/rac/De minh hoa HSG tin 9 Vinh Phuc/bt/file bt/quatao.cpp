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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            dp[i][j] = a[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[m][n];
    return 0;
}