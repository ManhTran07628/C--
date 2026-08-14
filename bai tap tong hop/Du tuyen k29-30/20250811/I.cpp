#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,h,w[107],v[107],dp[MM];
// dp[k] : trong luong be nhat de co the dat duoc 
// gia tri k 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    ll total = 0;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
        total += v[i];
    }
    fill(dp+1,dp+total+1,oo);
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = total;j >= v[i];j--) {
            if(dp[j-v[i]] != oo) 
                dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    ll ans = 0;
    for(int i = 1;i <= total;i++) {
        if(dp[i] <= h) ans = i;
    }
    cout << ans;
    return 0;
}