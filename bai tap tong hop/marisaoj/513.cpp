#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
int n,q,up[MM][LOG+1],h[MM];
vector<int> adj[MM];
void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v != par) {
            h[v] = h[u] + 1;
            up[v][0] = u;
            dfs(v,u);
        }
    }
}

void process()
{
    dfs(1,0);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int lca(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }

    if(u == v) return u;
    
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    up[1][0] = 1;
    process();
    while(q--) {
        int u,v;
        cin >> u >> v;
        int Lca = lca(u,v);
        if(u == Lca) cout << "MA";
        else if(v == Lca) cout << "RI";
        else cout << "SA";
        cout << '\n';
    }
    return 0;
}