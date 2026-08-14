#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int MOD = 1e9 + 7;
ll n,dp[MM][2];
vector<int> adj[MM];
int res = 0;
// 0 - den   1 - trang
void dfs(int u,int par)
{
    dp[u][0] = dp[u][1] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        dp[u][0] = (dp[u][0] * dp[v][1]) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0] % MOD + dp[u][1] * dp[v][1] % MOD) % MOD;
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
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1,0);
    cout << (dp[1][0] + dp[1][1]) % MOD;
    return 0;
}
