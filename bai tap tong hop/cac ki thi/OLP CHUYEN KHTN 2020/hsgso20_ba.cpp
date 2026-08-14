#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
const int MOD = 1e9 + 7;
int n,k,x;
ll dp[MM][MM][3];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k >> x;
    for(int num = 1;num <= 9;num++) {
        dp[1][(num == x)][num % 3]++;
    }
    for(int i = 1;i <= n;i++) {
        for(int t = 0;t <= min(i,k);t++) {
            for(int num = 0;num <= 9;num++) {
                for(int mod = 0;mod <= 2;mod++) {
                    int new_t = t + (num == x);
                    int new_mod = (num + mod) % 3;
                    dp[i + 1][new_t][new_mod] += dp[i][t][mod];
                    dp[i + 1][new_t][new_mod] %= MOD;
                }
            }
        }
    }
    // cout << dp[n][0][0] + dp[n][1][0];
    cout << dp[n][k][0];
    return 0;
}