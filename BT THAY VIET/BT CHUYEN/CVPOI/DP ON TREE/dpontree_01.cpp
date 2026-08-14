#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,dp[MM][2];
vector<int> adj[MM];
int res = 0;

void dfs(int u,int par)
{
    dp[u][1] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += dp[v][0];
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
    // for(int i = 1;i <= n;i++) cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    cout << max({dp[1][0],dp[1][1]});
    return 0;
}
