#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 90+7;
const int MOD = 1e9+7;
ll dp1[MM][MM][MM],dp2[MM][MM][MM],n; 
// dp1[i][j][u]  dp2[j][u][v];
char a[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #define taskname "palpath"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    if(a[1][1] == a[n][n]) {
        dp1[1][1][n] = 1;
        dp2[1][n][n] = 1;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            for(int u = n;u >= i;u--) {
                int v = 2*n+2-u-i-j;    
                if(u >= i && v >= j) {
                    if(a[i][j] == a[u][v]) {
                        ll cost = dp1[i-1][j][u+1] + dp2[j][u][v+1] + dp1[i][j-1][u+1] + dp2[j-1][u][v+1]; 
                        cost %= MOD;
                        dp1[i][j][u] = (dp1[i][j][u] + cost) % MOD;
                        dp2[j][u][v] = (dp2[j][u][v] + cost) % MOD;
                    }
                    if(i == u && j == v) ans = (ans + dp1[i][j][u]) % MOD;
                }
            }
        }
    }
    cout << ans;
    return 0;
}