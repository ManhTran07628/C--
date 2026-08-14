#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DAYSO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    fill(dp,dp+n+1,-1e9);
    ll max1 = 0;
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i - j >= 0) {
                dp[i] = max(dp[i],dp[i-j]);
            }
            else dp[i] = max(dp[i],dp[0]);
        }
        dp[i] += a[i];
       // cout << dp[i] << " ";
        max1 = max(max1,dp[i]);
    }
    cout << max1;
    return 0;
}