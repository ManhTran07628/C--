#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 1e9+7;
int n,d[MM],x[MM];

void readinput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> d[i] >> x[i];
    }
}

namespace subtask1
{
    const int MS = 1e3+7;
    ll dp[MS];
    void solve()
    {
        dp[1] = 1;
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            for(int t = i+1;t <= n;t++) {
                ll tmp = t-i;
                if(d[i] > 0 && tmp % d[i] == 0 && tmp / d[i] <= x[i]) {
                    dp[t] = (dp[i] + dp[t]) % MOD;
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask1::solve();
    return 0;
}