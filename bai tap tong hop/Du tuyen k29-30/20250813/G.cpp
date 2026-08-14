#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,w,a[MM],b[MM],dp[300001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "talent"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> w;
    ll s = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        s += b[i];
    }
    fill(dp+1,dp+s+1,oo);
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = s;j >= b[i];j--) {
            dp[j] = min(dp[j],dp[j-b[i]] + a[i]);
        }
    }
    ll ans = 0;
    for(int i = 1;i <= s;i++) {
        if(dp[i] >= w) {
            ll points = (double(i) / dp[i]) * 1000;
            ans = max(ans,points);
        }
    }
    cout << ans;
    return 0;
}