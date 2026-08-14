#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,vis[MM];
vector<int> adj[MM],res;
void dfs(int u,int par)
{
    res.push_back(u);
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(vis[v]) continue;
        for(auto child:adj[v]) {
            if(child == u) continue;
            dfs(child,v);
        }
        res.push_back(v);
    }
    vis[u] = 1;
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
    dfs(1,0); res.push_back(1);
    for(auto x:res) cout << x << ' ';
    return 0;
}