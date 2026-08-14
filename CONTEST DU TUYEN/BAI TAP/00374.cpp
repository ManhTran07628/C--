#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e6 + 7;
int n,dp[MM],a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i < n;i++) cin >> a[i];
    dp[1] = a[1];
    for(int i = 2;i <= n;i++) {
        dp[i] = min(dp[i-2] + a[i - 1],dp[i-1] + a[i - 1]);
    }
    cout << dp[n];
    return 0;
}