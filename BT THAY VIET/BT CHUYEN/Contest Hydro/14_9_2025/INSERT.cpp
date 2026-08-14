#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int LOG = 22;
int n,q,h[MM],up[MM][LOG+1],par[MM],edge_id[MM];
vector<pair<int,int>> adj[MM];
pair<int,int> qr[MM],edges[MM];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }   
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].fi >> qr[i].se;
    }
}


void dfs(int u)
{
    for(auto x:adj[u]) {
        int v = x.fi, id = x.se;
        if(up[u][0] != v) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            par[v] = u;
            edge_id[v] = id;
            dfs(v);
        }
    }
}

void process()
{
    up[1][0] = 1;
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int LCK(int u,int v) {
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

namespace solb
{
    int ans[MM];
    void solve()
    {
        process();
        for(int i = 1;i <= q;i++) {
            int u = qr[i].fi, v = qr[i].se;
            int lca = LCK(u,v);
    
            while(u != lca) {
                ans[edge_id[u]] = i;
                u = par[u];
            }

            while(v != lca) {
                ans[edge_id[v]] = i;
                v = par[v];
            }
        }
        for(int i = 1;i < n;i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}

namespace sol
{
    int ans[MM];
    struct DSU
    {
        vector<int> par,sz,min_h;
        DSU(int n): par(n+7),sz(n+7),min_h(n+7) {
            for(int i = 1;i <= n;i++) {
                par[i] = i;
                sz[i] = 1;
                min_h[i] = i;
            }
        };

        int find_set(int a)
        {
            if(a == par[a]) return a;
            return par[a] = find_set(par[a]);
        }

        void unite(int a,int b)
        {
            a = find_set(a);
            b = find_set(b);
            if(a == b) return;
            if(sz[a] < sz[b]) swap(a,b);
            sz[a] += sz[b];
            par[b] = a;
            if(h[min_h[a]] > h[min_h[b]]) {
                min_h[a] = min_h[b];
            }
        }
    };

    void solve()
    {
        process();
        DSU g(n+7);
        for(int i = q;i >= 1;i--) {
            int lca = LCK(qr[i].fi,qr[i].se);

            int u = qr[i].fi, v = qr[i].se;
            while(h[u] > h[lca]) {
                int min_node = g.min_h[g.find_set(u)];
                ans[edge_id[min_node]] = i;
                g.unite(par[min_node],min_node);
                u = par[min_node];
            }
            
            while(h[v] > h[lca]) {
                int min_node = g.min_h[g.find_set(v)];
                ans[edge_id[min_node]] = i;
                g.unite(par[min_node],min_node);
                v = par[min_node];
            }
        }

        for(int i = 1;i < n;i++) {
            cout << ans[i] << ' ';
        }

    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    // solb::solve();
    sol::solve();
    return 0;
}