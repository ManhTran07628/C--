#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,dp[MM][2],h[MM];
vector<int> adj[MM];

void dfs1(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs1(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] = max(dp[u][1],dp[v][0] + 1);
    }   
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);  
    cout << max(dp[1][1],dp[1][0]);
    return 0;
}