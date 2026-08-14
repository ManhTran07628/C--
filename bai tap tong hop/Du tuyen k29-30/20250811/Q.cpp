#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
ll n,k,dp[500][500],a[500],ps[500],maxl = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "snakes"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    for(int i = 0;i <= n;i++)
        for(int d = 0;d <= k;d++)
            dp[i][d] = oo;
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) {
        ll val = 0;
        for(int j = i;j >= 1;j--) {
            val = max(val,a[j]);
            ll len = i-j+1;
            for(int d = 0;d <= k;d++) {
                if(d > 0)
                    dp[i][d] = min(dp[i][d],dp[j-1][d-1]+val*len-(ps[i]-ps[j-1]));
                else if(j == 1) 
                    dp[i][0] = min(dp[i][0],val*len-(ps[i]-ps[j-1]));
            }
        }
    }
    ll ans = 0;
    cout << dp[n][k];
    return 0;
}