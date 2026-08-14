#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,dp[MM],min_op = oo;
vector<pii> adj[MM];

void dfs1(int u,int par)
{
    for(auto N:adj[u]) {
        int v = N.fi, type = N.se;
        if(v == par) continue;
        dfs1(v,u);
        dp[u] += dp[v];
        if(type == 0) dp[u]++;
    }
}

void dfs2(int u,int par)
{
    min_op = min(min_op,dp[u]);
    for(auto N:adj[u]) {
        int v = N.fi, type = N.se;
        if(v == par) continue;
        dp[v] = dp[u];
        if(type == 1) dp[v]++;
        else dp[v]--;
        dfs2(v,u);
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
        adj[u].push_back({v,1});
        adj[v].push_back({u,0});
    }
    dfs1(1,0);
    // cout << dp[1] << '\n';
    dfs2(1,0);
    cout << min_op << '\n';
    for(int i = 1;i <= n;i++) {
        if(dp[i] == min_op) cout << i << ' ';
    }
    return 0;
}