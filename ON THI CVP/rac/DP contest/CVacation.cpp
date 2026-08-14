#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+7;
ll a[N],b[N],c[N],dp[N][4];

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
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for(int i = 2;i <= n;i++) {
        dp[i][1] = max(dp[i-1][2],dp[i-1][3]) + a[i];
        dp[i][2] = max(dp[i-1][1],dp[i-1][3]) + b[i];
        dp[i][3] = max(dp[i-1][1],dp[i-1][2]) + c[i];
        //cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << '\n';
    }
    cout << max({dp[n][1],dp[n][2],dp[n][3]});
    return 0;  
}