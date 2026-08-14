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
    #define taskname "food"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n-1;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,dp[n-1][i]+a[n][i]);
    }
    cout << ans;
    return 0;
}