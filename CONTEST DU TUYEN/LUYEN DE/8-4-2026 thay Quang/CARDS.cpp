#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
const int MOD = 123456789;
ll n,k,m;

namespace brute
{
    ll dp[MM][101];
    void solve()
    {
        dp[0][0] = 1;
        for(int step = 1;step <= n;step++) {

            if(step % 2 == 1) {
                for(int j = 0;j < m;j++) 
                    for(int i = 1;i <= k;i += 2) {
                        dp[step][(i + j) % m] += dp[step - 1][j];
                        dp[step][(i + j) % m] %= MOD;
                    } 
            }
            else {
                for(int j = 0;j < m;j++) 
                    for(int i = 2;i <= k;i += 2) {
                        dp[step][(i + j) % m] += dp[step - 1][j];
                        dp[step][(i + j) % m] %= MOD;
                    }
            }

        }

        cout << dp[n][0];
    }
}

namespace subtask23
{
    ll C(int x,int type)
    {
        ll st = x;
        if(st % 2 != type) st += m;
        if(st % 2 != type) return 0;
        if(st > k) return 0;
        return (k - st) / (2 * m) + 1;
    }

    ll dp[MM][101];

    void solve()
    {
        dp[0][0] = 1;

        for(int i = 1;i <= n;i++) {
            for(int f = 0;f < m;f++) 
                for(int j = 0;j < m;j++) {
                    ll x = ((j - f) % m + m) % m;
                    ll cnt = C((x == 0 ? m : x),i % 2);
                    dp[i][j] = (dp[i][j] + dp[i - 1][f] % MOD * cnt % MOD) % MOD;
                }
        }
        cout << dp[n][0];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "CARDS"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k >> m;
    subtask23::solve();
    return 0;
}