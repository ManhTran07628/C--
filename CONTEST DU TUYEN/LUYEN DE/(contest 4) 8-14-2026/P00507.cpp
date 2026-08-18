#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
ll n,m;

namespace subtask13
{
    ll dp[MM][1 << 6];

    vector<int> nxt_vmask[MM];

    vector<int> vec;
    void Try(int id,int last_mask,int cur_mask)
    {
        if(id == m) {
            nxt_vmask[last_mask].push_back(cur_mask);
            return;
        }

        if(id + 1 < m && !(last_mask >> id & 1) && !(last_mask >> (id + 1) & 1))
            Try(id + 2,last_mask,cur_mask);
        
        if(last_mask >> id & 1) Try(id + 1,last_mask,cur_mask);
        else Try(id + 1,last_mask,cur_mask ^ (1 << id));
    }

    void solve()
    {
        dp[1][0] = 1;
        for(int mask = 0;mask < (1 << m);mask++) {
            Try(0,mask,0);
            // dp[1][mask] = 1;
        }

        for(int i = 1;i <= n;i++) {
            for(int mask = 0;mask < (1 << m);mask++) {
                for(auto nxt_mask:nxt_vmask[mask]) {
                    dp[i + 1][nxt_mask] += dp[i][mask];
                    dp[i + 1][nxt_mask] %= MOD;
                }
            }   
        }   
        
        cout << dp[n + 1][0];
    }
}

namespace subtask2
{
    void solve()
    {
        if(n % 2 == 0) cout << 1;
        else cout << 0;
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
    if(m == 1) subtask2::solve();
    else subtask13::solve();
    return 0;
}