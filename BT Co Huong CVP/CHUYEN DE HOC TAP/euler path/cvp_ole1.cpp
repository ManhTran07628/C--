#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,m,deg[MM],vis[MM];
vector<int> adj[MM];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        dfs(v);
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
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    dfs(1);
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            cout << "NO";
            return 0;
        }
    }
    int ok = 0;
    for(int i = 1;i <= n;i++) {
        if(deg[i] % 2 == 1) ok++;
    }
    if(ok == 0) cout << "YES";
    else cout << "NO";
    return 0;

}