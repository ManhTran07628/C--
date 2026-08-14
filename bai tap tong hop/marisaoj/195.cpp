#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
ll n,q,up[MM][LOG+1],high[MM],lg2[MM];
vector<ll> adj[MM];

int get_kth_ancestor(int u,int k);

void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) {
        lg2[i] = lg2[i/2] + 1;
    }
}

void dfs(int u)
{
    for(auto v:adj[u]) {
        if(v != up[u][0]) {
            up[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}

void process()
{
    BuildLog2Arr();
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int lca(int u,int v)
{
    if(high[v] > high[u]) return lca(v,u);

    for(int i = LOG;i >= 0;i--) {
        if(high[up[u][i]] >= high[v]) 
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

int Query(int u,int v,int w)
{
    int Lca = lca(u,v);
    int dis1 = high[u]-high[Lca];
    int dis2 = high[v]-high[Lca];
    int dist = dis1 + dis2;
    if(w >= dist) return v;
    if(w <= dis1) return get_kth_ancestor(u,w);
    else return get_kth_ancestor(v,dis2-(w-dis1));
}

int get_kth_ancestor(int u,int k)
{
    for(int i = LOG;i >= 0;i--) {
        if(k >> i & 1) {
            u = up[u][i];
        }
    }
    return u;
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
    process();
    while(q--) {
        int u,v,w;
        cin >> u >> v >> w;
        cout << Query(u,v,w) << '\n';
    }
    return 0;
}