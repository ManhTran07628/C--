#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3e5+7;
const int LOG = 18;
int n,m,h[MM],up[MM][LOG+1],Max[MM][LOG+1],parent[MM],ds[MM];
int mst_val = 0;
vector<pair<int,int>> adj[MM],g[MM];
struct Edge{
    int u,v,w,id;
};
vector<Edge> edges,mst,edges_a;

int find_sets(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find_sets(parent[a]);
}

bool union_sets(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return 0;
    parent[b] = a;
    return 1;
}
void dfs(int u)
{
    for(auto x:g[u]) {
        int v = x.fi,w = x.se;
        if(v != up[u][0]) {
            up[v][0] = u;
            Max[v][0] = w;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void build_MST()
{
    sort(edges.begin(),edges.end(), [](Edge &a,Edge &b){
        return a.w < b.w;
    });
    // cout << edges.size() << '\n';
    for(int i = 1;i < edges.size();i++) {
        auto Node = edges[i];
        if(!union_sets(Node.u,Node.v)) continue;
        mst.push_back({Node.u,Node.v,Node.w});
        g[Node.u].push_back({Node.v,Node.w});
        g[Node.v].push_back({Node.u,Node.w});
        ds[Node.id] = 1;
        mst_val += Node.w;
    }
}

void build_LCA()
{
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            Max[i][j] = max(Max[i][j-1],Max[up[i][j-1]][j-1]);
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

int query(int u,int v,int cur_w)
{
    int Lca = lca(u,v);
    int dist1 = h[u] - h[Lca], dist2 = h[v] - h[Lca];
    int max_w = 0;
    for(int i = LOG;i >= 0;i--) {
        if(dist1 >> i & 1) {
            max_w = max(max_w,Max[u][i]);
            u = up[u][i];
        }
    }
    for(int i = LOG;i >= 0;i--) {
        if(dist2 >> i & 1) {
            max_w = max(max_w,Max[v][i]);
            v = up[v][i];
        }
    }
    int res = mst_val - max_w + cur_w;
    return (mst_val - max_w + cur_w);
}

void solve()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) parent[i] = i;
    edges.push_back({0,0,0});
    edges_a.push_back({0,0,0});
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w,i});
        edges_a.push_back({u,v,w,i});
    }
    up[1][0] = 1;
    build_MST();
    build_LCA();
    int ans = oo;
    for(int i = 1;i <= n;i++) {
        if(!ds[i]) {
            int res = query(edges_a[i].u,edges_a[i].v,edges_a[i].w);
            // cout << res << '\n';
            if(res > mst_val) {
                ans = min(ans,res);
            }
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}