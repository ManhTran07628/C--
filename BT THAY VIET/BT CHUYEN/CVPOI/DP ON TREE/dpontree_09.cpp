#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,vis[MM];
vector<int> adj[MM];
int res = 0;

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        if(!vis[u] && !vis[v]) {
            res++;
            vis[u] = vis[v] = 1;
        }
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
    cout << res;
    return 0;
}
