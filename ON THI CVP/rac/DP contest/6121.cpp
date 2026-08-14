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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            if(j > 1 && j < i) dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
            else {
                if(j == i) dp[i][j] = a[i][j] + dp[i-1][j-1];
                else dp[i][j] = a[i][j] + dp[i-1][j];
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,dp[n][i]);
    }
    cout << ans;
    return 0;
}