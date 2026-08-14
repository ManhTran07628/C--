#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,K,D;
struct Node{int s,e,v;} events[MM];

namespace sol
{
    int p[MM],q[MM],e[MM];
    void solve()
    {
        sort(events+1,events+n+1,[] (Node a,Node b){
            if(a.e != b.e) return a.e < b.e;
            return a.s < b.s;
        });

        for(int i = 1;i <= n;i++) e[i] = events[i].e;

        for(int i = 1;i <= n;i++) {
            p[i] = upper_bound(e+1,e+i,events[i].s) - e - 1;
            q[i] = upper_bound(e+1,e+i,events[i].s + D) - e - 1;
        }

        ll res = 0;
        vector<ll> old_dp0,old_dp1;
        old_dp0.assign(n + 1,0);
        old_dp1.assign(n + 1,0);

        for(int k = 1;k <= K;k++) {
            vector<ll> new_dp0,new_dp1;
            new_dp0.assign(n + 1,0);
            new_dp1.assign(n + 1,0);
            for(int i = 1;i <= n;i++) {
                // dp[i][k][0] = dp[i][k][1] = events[i].v;

                new_dp0[i] = max(new_dp0[i - 1],old_dp0[ p[i] ] + events[i].v);
                new_dp1[i] = max(new_dp1[i - 1],max(old_dp1[ p[i] ],
                    old_dp0[ q[i] ]) + events[i].v);
                
            }
            res = max(res,new_dp1[n]);
            res = max(res,new_dp0[n]);

            old_dp0 = new_dp0;
            old_dp1 = new_dp1;
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
    cin >> n >> K >> D;
    for(int i = 1;i <= n;i++) cin >> events[i].s >> events[i].e >> events[i].v;
    // subtask4::solve();
    sol::solve();
    return 0;
}
