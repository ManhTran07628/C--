#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,k;
ll a[MM],T,ps[MM];

ll getval(ll S)
{
    return (S - T) * (S - T);
}

namespace subtask2
{
    void solve()
    {
        cout << getval(ps[n]);
    }
}

namespace subtask3
{
    void solve()
    {
        ll res = oo;
        for(int i = 1;i < n;i++) {
            ll s1 = getval(ps[i]), s2 = getval(ps[n] - ps[i]);
            res = min(res,s1 + s2);
        }
        cout << res;
    }
}

namespace sol
{
    vector<ll> old_dp,nxt_dp;
    ll C(int l,int r)
    {
        ll sum = ps[r] - ps[l - 1] - T;
        return sum * sum;
    }

    void dnc(int L,int R,int optL,int optR)
    {
        if(L > R) return;
        int mid = (L + R) / 2;

        ll best_L = oo, pos_L = -1;
        for(int i = optL;i <= min(mid,optR);i++) {
            ll cost = old_dp[i - 1] + C(i,mid);
            if(cost < best_L) {
                best_L = cost;
                pos_L = i;
            }
        }
        nxt_dp[mid] = best_L;
        dnc(L,mid - 1,optL,pos_L);
        dnc(mid + 1,R,pos_L,optR);
    }

    void solve()
    {
        old_dp.assign(MM,oo);
        nxt_dp.assign(MM,oo);
        old_dp[0] = 0;
        nxt_dp[0] = 0;
        
        for(int i = 1;i <= n;i++) {
            old_dp[i] = C(1,i);
        }

        for(int d = 2;d <= k;d++) {
            dnc(1,n,1,n);
            old_dp = nxt_dp;
        }

        cout << old_dp[n];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> T;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    sol::solve();
    // if(k == 1) subtask2::solve();
    // else subtask3::solve();
    return 0;
}