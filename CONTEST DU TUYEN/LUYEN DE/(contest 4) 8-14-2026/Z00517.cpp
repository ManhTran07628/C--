#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 4e4 + 7;
int n,m,q,T,ans[MM];

struct Edge{int u,v,id;};
vector<Edge> edges,qr[MM];
vector<int> st[MM * 4];

void update(int id,int l,int r,int u,int v,int edge_id)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id].push_back(edge_id);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,edge_id);
    update(id*2+1,mid+1,r,u,v,edge_id);
}

struct DSU
{
    struct Snapshot{int u,v,par_v;};
    vector<Snapshot> snapshot;

    int par[MM] = {}, sz[MM] = {};

    void build()
    {
        for(int i = 1;i < MM;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return find_sets(par[a]);
    }

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) {
            snapshot.push_back({0,0,0});
            return;
        }
        if(sz[a] < sz[b]) swap(a,b);
        
        snapshot.push_back({a,b,par[b]});

        par[b] = a;
        sz[a] += sz[b];
    }

    void rollback()
    {
        int v = snapshot.back().v, par_v = snapshot.back().par_v;
        int u = snapshot.back().u;
        snapshot.pop_back();
        if(u == 0) return;

        par[v] = par_v;
        sz[u] -= sz[v];
    }
} g;

void dfs(int id,int l,int r)
{
    int sz = g.snapshot.size();
    for(auto i:st[id]) {
        int u = edges[i].u, v = edges[i].v;
        g.Unite(u,v);
    }

    if(l == r) {
        for(auto i:qr[l]) {
            int u = i.u, v = i.v;
            ans[i] = (g.find_sets(u) == g.find_sets(v));
        }

        while(g.snapshot.size() != sz) g.rollback();
        return;
    }
    int mid = (l + r) / 2;
    dfs(id*2,l,mid);
    dfs(id*2+1,mid+1,r);

    while(g.snapshot.size() != sz) g.rollback();
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
    cin >> n >> m >> q >> T;
    for(int i = 1;i <= m;i++) {
        int u,v,l,r; cin >> u >> v >> l >> r;
        update(1,1,T,l,r,i - 1);
        edges.push_back({u,v,0});
    }

    for(int i = 1;i <= q;i++) {
        int t,a,b; cin >> t >> a >> b;
        qr[t].push_back({a,b,i});
    }

    g.build();
    return 0;
}