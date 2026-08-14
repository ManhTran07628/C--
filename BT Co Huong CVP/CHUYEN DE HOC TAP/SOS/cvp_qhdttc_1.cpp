#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,a[MM];
ll dp[1 << 20];

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
    for(int i = 0;i < (1 << n);i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 0;i < n;i++)
        for(int mask = 0;mask < (1 << n);mask++) {
            if(mask >> i & 1)
                dp[mask] += dp[mask ^ (1 << i)];
        }
    for(int i = 0;i < (1 << n);i++) cout << dp[i] << ' ';
    return 0;
}