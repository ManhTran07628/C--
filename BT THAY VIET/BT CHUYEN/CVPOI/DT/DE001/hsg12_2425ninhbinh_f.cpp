#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int LOG = 18;
int n,q;
vector<pii> adj[MM];
struct Edge{int u,v,w;};
vector<Edge> edges;

void init()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
}

struct HLD
{
    int up[MM][LOG + 1],h[MM],in[MM],tour[MM],val[MM];
    int heavy[MM],head[MM],m = 0;

    int dfs(int u)
    {
        int max_sz = 0, cur_sz = 1;
        for(auto U:adj[u]) {
            int v = U.fi;
            if(up[u][0] == v) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            int child_sz = dfs(v);
            cur_sz += child_sz;
            if(child_sz > max_sz) {
                max_sz = child_sz;
                heavy[u] = v;
            }
        }
        return cur_sz;
    }

    void decompose(int u,int H)
    {
        in[u] = ++m; head[u] = H;
        tour[m] = u;
        if(heavy[u]) decompose(heavy[u],H);

        for(auto U:adj[u]) {
            int v = U.fi;
            if(v != up[u][0] && v != heavy[u])
                decompose(v,v);
        }
    }

    int LCK(int u,int v)
    {
        if(h[v] > h[u]) swap(u,v);
        for(int i = LOG;i >= 0;i--)
            if(h[ up[u][i] ] >= h[v])
                u = up[u][i];
        if(u == v) return u;
        for(int i = LOG;i >= 0;i--)
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        return up[u][0];
    }

    void process()
    {
        val[1] = oo;
        dfs(1);
        decompose(1,1);

        for(auto U: edges) {
            int u = U.u, v = U.v, w = U.w;
            if(up[u][0] == v) val[u] = w; // u la con cua v
            else val[v] = w; // v la con cua u
        }

        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i <= n;i++)
                up[i][j] = up[ up[i][j-1] ][j-1];
    }

    int st[MM * 4],closed[MM * 4];

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = val[ tour[l] ];
            return;
        }
        int mid = (l + r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = min(st[id*2],st[id*2+1]);
    }

    void update_node(int id,int l,int r,int pos)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            closed[id] = 1;
            return;
        }
        int mid = (l + r) / 2;
        update_node(id*2,l,mid,pos);
        update_node(id*2+1,mid+1,r,pos);
        closed[id] = closed[id*2] + closed[id*2+1];
    }

    int get_node(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return closed[id];
        int mid = (l + r) / 2;
        return get_node(id*2,l,mid,u,v) + get_node(id*2+1,mid+1,r,u,v);
    }

    int get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return oo;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
    }


    bool check_closed_path(int u,int v)
    {
        int lca = LCK(u,v);
        int res = oo;
        while(head[u] != head[lca]) {
            int getChain = get_node(1,1,n,in[ head[u] ],in[u]);
            if(getChain > 0) return 1;
            u = up[ head[u] ][0];
        }

        while(head[v] != head[lca]) {
            int getChain = get_node(1,1,n,in[ head[v] ],in[v]);
            if(getChain > 0) return 1;
            v = up[ head[v] ][0];
        }

        if(h[u] < h[v]) {
            int getChain = get_node(1,1,n,in[u],in[v]);
            if(getChain > 0) return 1;
        }
        else {
            int getChain = get_node(1,1,n,in[v],in[u]);
            if(getChain > 0) return 1;
        }
        return 0;
    }

    int getquery(int u,int v)
    {
        if(u == v) return 0;
        int lca = LCK(u,v);
        int res = oo;
        while(head[u] != head[lca]) {
            int getChain = get(1,1,n,in[ head[u] ],in[u]);
            res = min(res,getChain);
            u = up[ head[u] ][0];
        }

        while(head[v] != head[lca]) {
            int getChain = get(1,1,n,in[ head[v] ],in[v]);
            res = min(res,getChain);
            v = up[ head[v] ][0];
        }

        if(h[v] < h[u]) res = min(res, get(1,1,n,in[v] + 1,in[u]));
        else res = min(res, get(1,1,n,in[u] + 1,in[v]));
        return res;
    }

    void Build() {
        process();
        build(1,1,n);
    }
} g;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    g.Build();

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u,v; cin >> u >> v;
            if(g.get_node(1,1,n,g.in[u],g.in[u]) || g.get_node(1,1,n,g.in[v],g.in[v])) {
                cout << -1 << '\n';
                continue;
            }
            
            if(u == v) {
                cout << 0 << '\n';
                continue;
            }


            if(g.check_closed_path(u,v) == 1) {
                cout << -1 << '\n';
                continue;
            }
            cout << g.getquery(u,v) << '\n';
        }
        else {
            int u; cin >> u;
            g.update_node(1,1,n,g.in[u]);
        }
    }
    return 0;
}