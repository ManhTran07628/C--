#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e5 + 7;
const int LOG = 19;
int n;
vector<pii> adj[MM];

struct Edges{int u,v,w;};
vector<Edges> edges;

namespace subtask2
{
    ll dp[MM],sz[MM],ans[MM];

    void dfs1(int u,int par)
    {
        sz[u]++;
        for(auto N:adj[u]) {
            int v = N.fi;
            if(v == par) continue;
            dfs1(v,u);
            dp[u] += dp[v];// + sz[v];
            sz[u] += sz[v];
        }
        dp[u] += sz[u] - 1;
    }


    ll res = 0;
    void dfs2(int u,int par)
    {
        for(auto N:adj[u]) {
            int v = N.fi;
            if(v == par) continue;
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            dfs2(v,u);
        }
    }

    void solve()
    {
        dfs1(1,0);
        ans[1] = dp[1];
        dfs2(1,0);
        ll res = 0;
        for(int i = 1;i <= n;i++) res += ans[i];
        cout << res / 2;
    }
}

namespace sol
{
    struct DSU
    {
        ll par[MM] = {}, sz[MM] = {};
        vector<pii> rb;

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
            if(a == b) return;
            if(sz[b] > sz[a]) swap(a,b);
            rb.push_back({a,b});
            sz[a] += sz[b];
            par[b] = a;
        }

        void rollback()
        {
            pii c = rb.back();
            rb.pop_back();
            int a = c.fi, b = c.se;
            sz[a] -= sz[b];
            par[b] = b;
        }
    } g;

    vector<pii> st[MM * 4], weight[MM];
    ll res = 0;

    void update(int id,int l,int r,int u,int v,pii edge)
    {
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            st[id].push_back(edge);
            return;
        }
        int mid = (l + r) / 2;
        update(id*2,l,mid,u,v,edge);
        update(id*2+1,mid+1,r,u,v,edge);
    }


    void get(int id,int l,int r)
    {
        int sz = g.rb.size();
        for(auto E:st[id]) {
            int u = E.fi, v = E.se;
            g.Unite(u,v);
        }

        if(l == r) {
            for(auto E:weight[l]) {
                int u = E.fi, v = E.se;
                res += g.sz[ g.find_sets(u) ] * g.sz[ g.find_sets(v) ];
            }

            while(g.rb.size() > sz) {
                g.rollback();
            }

            return;
        }

        int mid = (l + r) / 2;
        get(id*2,l,mid);
        get(id*2+1,mid+1,r);

        while(g.rb.size() > sz) {
            g.rollback();
        }
    }

    void solve()
    {
        g.build();
        sort(edges.begin(),edges.end(),[] (Edges a, Edges b){return a.w < b.w;});
        for(auto E:edges) {
            int u = E.u, v = E.v, w = E.w;
            update(1,1,n,1,w - 1,{u,v});
            update(1,1,n,w + 1,n,{u,v});
            weight[w].push_back({u,v});
        }
        get(1,1,n);
        cout << res;
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
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    sol::solve();
    return 0;
}