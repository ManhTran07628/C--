#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 100 + 7;
const int MOD = 1e9 + 7;
int n,m,a[MM],b[MM];
int mp[MM];

namespace subtask1
{
    int res = 0;
    bool isValid()
    {
        for(int i = 1;i < n;i++) {

            if(b[i] == 2) {
                if(b[i+1] == b[i]) return 0;
            }

        }
        return 1;
    }

    void Try(int id)
    {
        if(id == n + 1) {
            if(isValid()) {
                for(int i = 1;i <= n;i++) cout << b[i] << ' ';
                cout << '\n';
            }
            res += isValid();
            return;
        }
        b[id] = 1;
        Try(id + 1);
        
        b[id] = 2;
        Try(id + 1);
    }

    void solve()
    {
        Try(1);
        cout << res;
    }
}

namespace sol
{
    ll dp[MM][10];
    void solve()
    {
        for(int i = 1;i <= 8;i++) {
            if(mp[i] == 1) 
                dp[1][i] = 1;
        }

        for(int i = 1;i < n;i++) {

            for(int nums = 1;nums <= 8;nums++) 
                if(mp[nums]) {
                    // th1
                    int j = i + 1;
                    for(int nxt_nums = 1;nxt_nums <= 8;nxt_nums++) {
                        if(nxt_nums == nums) continue;
                        if(mp[nxt_nums]) {
                            dp[j][nxt_nums] += dp[i][nums];
                            dp[j][nxt_nums] %= MOD;
                        }
                    }

                    // th2
                    if(i + nums <= n) {
                        dp[i + nums][nums] += dp[i][nums];
                        dp[i + nums][nums] %= MOD;
                    }
                }
            

        }
        ll res = 0;
        for(int i = 1;i <= 8;i++) {
            if(mp[i] == 1) res = (res + dp[n][i]) % MOD;
        }
        cout << res - 1;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
        mp[ a[i] ] = 1;
    }
    sol::solve();

    return 0;
}