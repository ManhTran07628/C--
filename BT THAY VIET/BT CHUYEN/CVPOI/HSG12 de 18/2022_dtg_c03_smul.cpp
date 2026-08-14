#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int S2 = 1e3+7;
ll n,k,a[MM];


namespace subtask1
{
    void solve()
    {
        ll res = oo;
        for(int mask = 1;mask < (1 << n);mask++) {
            ll mul = 1,sum = 0;
            for(int i = 0;i < n;i++) 
                if(mask >> i & 1) {
                    mul *= a[i+1];
                    sum += a[i+1];
                }

            if(mul % k == 0) res = min(res,sum);
        }
        if(res == oo) cout << "No Solution!";
        else cout << res;
    }
}


namespace subtask2
{
    map<ll,ll> dp;

    void solve()
    {
        dp[1] = 0;
        for(int i = 1;i <= n;i++) {
            ll g = __gcd(a[i],k);
            if(g == 1) continue;

            map<ll,ll> cur = dp;

            for(auto j:cur) {
                ll d = j.fi;
                ll cost = j.se;
                ll new_d = __gcd(d * g,k);
                if(!dp.count(new_d)) dp[new_d] = oo;
                dp[new_d] = min(dp[new_d],cost + a[i]);
            }
        }

        if(!dp.count(k) || dp[k] == oo) cout << "No Solution!";
        else cout << dp[k];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    subtask2::solve();
    return 0;
}