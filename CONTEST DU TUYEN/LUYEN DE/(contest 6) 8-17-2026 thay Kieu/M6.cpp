#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9 + 7
#define pii pair<int,int>
const int MM = 3e5 + 7;
const int LOG = 18;
int n,m;
struct Edge{int u,v,w,is_mst = 0;};
vector<Edge> edges;

struct DSU
{
    int par[MM] = {};
    void build()
    {
        for(int i = 1;i < MM;i++) 
            par[i] = i;
    }

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    bool Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        par[b] = a;
        return 1;
    }
} g;


vector<pii> adj[MM];
ll mst_cost = 0;

int up[MM][LOG + 1],h[MM],st[MM][LOG + 1];

void dfs(int u)
{
    for(auto N:adj[u]) {
        int v = N.fi, w = N.se;
        if(up[u][0] == v) continue;
        up[v][0] = u;
        st[v][0] = w;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

void build_MST()
{
    g.build();
    sort(edges.begin(),edges.end(),[] (Edge a,Edge b){return a.w < b.w;});
    for(auto &E:edges) {
        if(!g.Unite(E.u,E.v)) continue;
        mst_cost += E.w;
        adj[E.u].push_back({E.v,E.w});
        adj[E.v].push_back({E.u,E.w});
        E.is_mst = 1;
    }
    dfs(1);
    up[1][0] = 1;
    st[1][0] = oo;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
            st[i][j] = max(st[i][j - 1],st[ up[i][j - 1] ][j - 1]);
        }
}

int LCK(int u,int v)
{
    if(h[u] < h[v]) swap(u,v);
    for(int i = LOG;i >= 0;i--) 
        if(h[ up[u][i] ] >= h[v]) {
            u = up[u][i];
        }
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i]; v = up[v][i];
        }
    } 
    return up[u][0];
}

int Min_edge(int u,int lca)
{
    int dist = h[u] - h[lca];
    int weight = 0;
    for(int i = LOG;i >= 0;i--) {
        if(dist >> i & 1) {
            weight = max(weight,st[u][i]);
            u = up[u][i];
        }
    }
    return weight;
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
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    build_MST();
    ll res = 1e18;
    for(auto E:edges) {
        int u = E.u, v = E.v, w = E.w;
        if(E.is_mst) continue;

        // cout << u << ' ' << v << ' ' << w << '\n';
        int lca = LCK(u,v);
        int val = max(Min_edge(u,lca),Min_edge(v,lca));
        ll new_cost = mst_cost - val + w;
        if(new_cost > mst_cost)
            res = min(res,new_cost);
    }
    if(res == (ll) 1e18) cout << -1;
    else cout << res;
    return 0;
}