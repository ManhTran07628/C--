#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int LOG = 18;
const int MM = 2e5+7;
int n,m,q;
struct Edge{int u,v,w;}; vector<Edge> edges,MSTedges;
vector<pair<int,int>> adj[MM],MSTadj[MM],query;
 
void init()
{
    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v,i});
    }
}
 
struct LCK
{
    int up[MM][LOG+1],Max[MM][LOG+1],h[MM],vis[MM];
 
    void dfs(int u,vector<pair<int,int>> adj[])
    {
        vis[u] = 1;
        for(auto E:adj[u]) {
            int v = E.fi, w = E.se;
            if(!vis[v]) {
                up[v][0] = u;
                Max[v][0] = w;
                h[v] = h[u] + 1;
                dfs(v,adj);
            }
        }
    }
 
    void process()
    {
        for(int i = 1;i <= n;i++){
            if(!vis[i] && !MSTadj[i].empty()){
                dfs(i,MSTadj);
            }
        }
        for(int j = 1;j <= LOG;j++) {
            for(int i = 1;i <= n;i++) {
                up[i][j] = up[ up[i][j-1] ][j-1];
                Max[i][j] = max(Max[i][j-1],Max[ up[i][j-1] ][j-1]);
            }
        }
    }
 
    int find_lck(int u,int v)
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
};
 
LCK d;
 
struct DSU
{
    vector<int> par,sz;
    DSU(int n) : par(n+7),sz(n+7) {};
    void make_sets()
    {
        for(int i = 1;i <= n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
 
    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }
 
    bool unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        if(sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
        return 1;
    }
};
 
DSU g(MM);
 
void make_MST()
{
    sort(edges.begin(),edges.end(),[](Edge &a, Edge &b){
        return a.w < b.w;
    });
    g.make_sets();
    for(auto E:edges) {
        int u = E.u, v = E.v, w = E.w;
        if(!g.unite(u,v)) continue;
        MSTedges.push_back({u,v,w});
        MSTadj[u].push_back({v,w});
        MSTadj[v].push_back({u,w});
    }
 
    d.process();
}
 
int QueryPath(int u,int v)
{
    int lck = d.find_lck(u,v);
    int distU = d.h[u] - d.h[lck];
    int distV = d.h[v] - d.h[lck];
    int Max_edge = 0;
    if(g.find_sets(u) != g.find_sets(v)) return -1;
    for(int i = LOG;i >= 0;i--) {
        if(distU >> i & 1) {
            Max_edge = max(Max_edge,d.Max[u][i]);
            u = d.up[u][i];
        }
    }
    for(int i = LOG;i >= 0;i--) {
        if(distV >> i & 1) {
            Max_edge = max(Max_edge,d.Max[v][i]);
            v = d.up[v][i];
        }
    }
    return Max_edge;
}
 
void solve()
{
    make_MST();
    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << QueryPath(a,b) << '\n';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}