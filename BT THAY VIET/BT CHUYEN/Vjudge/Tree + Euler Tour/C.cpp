#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int LOG = 18;
int n,q,up[MM][LOG+1],h[MM];
vector<int> adj[MM];

void load_graph()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v = i+1;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(up[u][0] != v) {
            h[v] = h[u] + 1;
            up[v][0] = u;
            dfs(v,u);
        }
    }
}

void process()
{
    dfs(1,0);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int LCK(int u,int v)
{
    if(h[u] < h[v]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }
    if(u == v) return u;

    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

void solve()
{
    process();
    while(q--) {
        int u,v;
        cin >> u >> v;
        int lck = LCK(u,v);
        cout << lck << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}