#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 4444 + 7;
int n,m,h[MM],vis[MM],res = 0;
vector<int> adj[MM];

void dfs(int u,int par)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!vis[v]) {
            h[v] = h[u] + 1;
            dfs(v,u);
        }
        else if(vis[v] == 1) {
            res = max(res,h[u] - h[v] + 1);
        }
    }
    vis[u] = 2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "maxcycle"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0); 
    cout << res;
    return 0;
}