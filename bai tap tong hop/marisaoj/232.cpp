#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;
int n;
vector<int> adj[MM];
ll dp[MM][4];


void dfs(int u,int par)
{
    dp[u][1] = dp[u][2] = dp[u][3] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        dp[u][1] = (dp[u][1] * dp[v][2] + dp[u][1] * dp[v][3]) % MOD;
        dp[u][2] = (dp[u][2] * dp[v][1] + dp[u][2] * dp[v][3]) % MOD;
        dp[u][3] = (dp[u][3] * dp[v][1] + dp[u][3] * dp[v][2]) % MOD;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    // for(int i = 1;i <= n;i++) cout << i << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << '\n';
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD;
    return 0;
}