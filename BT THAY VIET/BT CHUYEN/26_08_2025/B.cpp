#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
ll n,t,h[MM],d[MM];

void init()
{
    cin >> n >> t;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= t;i++) cin >> d[i];
}

namespace subtask1
{
    bool checksub1()
    {
        return (n == 2 && t == 1);
    }

    void solve()
    {
        if(abs(h[1] - h[2]) <= d[1]) cout << max(h[1],h[2]);
        else cout << h[1] + h[2];
    }
}

namespace subtask3
{
    ll dp[MM];
    void solve()
    {
        ll lim = 1e9;
        sort(h+1,h+n+1);

        for(int i = 1;i <= n;i++) dp[i] = oo;
        dp[0] = 0;
        for(int q = 1;q <= t;q++) {
            ll diff = d[q];
            dp[1] = h[1];
            for(int i = 2;i <= n;i++) {
                ll max_val = 0,min_val = lim;
                for(int j = i;j >= i-1;j--) {
                    max_val = max(max_val,h[j]);
                    min_val = min(min_val,h[j]);
                    if(max_val-min_val <= diff) {
                        dp[i] = min(dp[i],dp[j-1] + max_val);
                    }
                }
            }
            cout << dp[n] << '\n';

            fill(dp+1,dp+n+1,oo);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    if(subtask1::checksub1()) subtask1::solve();
    else subtask3::solve();
    return 0;
}