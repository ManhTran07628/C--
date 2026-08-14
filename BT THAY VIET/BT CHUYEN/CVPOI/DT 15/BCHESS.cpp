#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 100 + 7, MOD = 9999973;
int n,m;

namespace subtask1
{
    int row[MM],col[MM];

    vector<int> state_row;

    int res = 0;
    void Try(int x,int y)
    {
        if(y > m) {
            Try(x + 1,1);
            return;
        }
        if(x > n) {
            res++;
            return;
        }

        if(row[x] + 1 <= 2 && col[y] + 1 <= 2) {
            row[x]++;
            col[y]++;
            Try(x,y + 1);
            row[x]--;
            col[y]--;
        }

        Try(x,y + 1);
    }

    void solve()
    {
        Try(1,1);
        cout << res % MOD;
    }
}

namespace subtask2
{
    ll dp[MM][MM][MM];
    void solve()
    {
        dp[0][0][0] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j <= m;j++)
                for(int k = 0;k + j <= m;k++) {
                    ll c0 = (m - j - k);
                    ll val = dp[i - 1][j][k];

                    dp[i][j][k] += val % MOD;

                    if(c0 >= 1) dp[i][j + 1][k] += val * c0 % MOD;

                    if(j - 1 >= 0) dp[i][j - 1][k + 1] += val * j % MOD;

                    if(c0 >= 1) {
                        dp[i][j + 2][k] += val * (c0 * (c0 - 1) / 2);
                        dp[i][j + 2][k] %= MOD;
                    }

                    if(j - 2 >= 0) {
                        dp[i][j - 2][k + 2] += val * (j * (j - 1) / 2);
                        dp[i][j - 2][k + 2] %= MOD;
                    }

                    if(c0 >= 1) {
                        dp[i][j][k + 1] += val * c0 * j;
                        dp[i][j][k + 1] %= MOD;
                    }
                }
        }
        ll res = 0;
        for(int j = 0;j <= m;j++)
            for(int k = 0;k <= m;k++) {
                res = (res + dp[n][j][k]) % MOD;
            }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    subtask2::solve();
    return 0;
}