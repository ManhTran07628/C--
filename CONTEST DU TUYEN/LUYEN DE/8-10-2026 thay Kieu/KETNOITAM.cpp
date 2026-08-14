#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,q;
struct QR{char type;int u,v,id;} qr[MM];

namespace subtask1
{
    vector<pii> edges;
    int vis[MM] = {};
    vector<int> adj[MM];

    void dfs(int u)
    {
        vis[u] = 1;
        for(auto v:adj[u]) {
            if(vis[v]) continue;
            dfs(v);
        }
    }

    bool check(int u,int v)
    {
        for(int i = 1;i <= n;i++) {
            adj[i].clear();
            vis[i] = 0;
        }
        for(auto E:edges) {
            adj[E.fi].push_back(E.se);
            adj[E.se].push_back(E.fi);
        }

        dfs(u);
        return vis[v];
    }

    void solve()
    {
        for(int t = 1;t <= q;t++) {
            if(qr[t].type == '+') edges.push_back({qr[t].u,qr[t].v});
            else if(qr[t].type == '-') edges.erase(edges.begin() + qr[t].id - 1);
            else if(qr[t].type == '?') cout << check(qr[t].u,qr[t].v) << '\n';
        }
    }
}

namespace subtask2
{
    bool checksub2()
    {
        for(int t = 1;t <= q;t++) {
            if(qr[t].type == '-') return 0;
        }
        return 1;
    }

    struct DSU
    {
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
            return par[a] = find_sets(par[a]);
        }

        void Unite(int a,int b)
        {
            a = find_sets(a);
            b = find_sets(b);
            if(a == b) return;
            if(sz[a] < sz[b]) swap(a,b);
            par[b] = a;
            sz[a] += sz[b];
        }
    } g;


    void solve()
    {
        g.build();
        for(int t = 1;t <= q;t++) {
            if(qr[t].type == '+') g.Unite(qr[t].u,qr[t].v);
            else if(qr[t].type == '?') {
                cout << (g.find_sets(qr[t].u) == g.find_sets(qr[t].v)) << '\n';
            }
        }
    }
}

namespace sol
{
    struct DSU
    {
        int par[MM] = {}, sz[MM] = {};

        struct Snapshot{int a,b,old_b,sz_b;};
        vector<Snapshot> snapshot;

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
                snapshot.push_back({0,0,0,0});
                return;
            }
            if(sz[a] < sz[b]) swap(a,b);

            snapshot.push_back({a,b,par[b],sz[b]});
            par[b] = a;
            sz[a] += sz[b];
        }

        void rollback()
        {
            int a = snapshot.back().a, b = snapshot.back().b;
            int old_b = snapshot.back().old_b, sz_b = snapshot.back().sz_b;
            snapshot.pop_back();

            if(a == 0 && b == 0) return;

            sz[a] -= sz_b;
            par[b] = old_b;

        }
    } g;    

    int lastpos[MM];
    map<int,pii> mp;
    int cur_id = 0;

    vector<pii> st[MM * 4];
    pii askqueries[MM] = {};
    int ans[MM];

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

    void dfs(int id,int l,int r)
    {
        int sz = g.snapshot.size();
        for(auto edges:st[id]) {
            int u = edges.fi, v = edges.se;
            g.Unite(u,v);
        }

        if(l == r) {
            pii edge = askqueries[l];
            int u = edge.fi, v = edge.se;
            if(u != 0 && v != 0 && g.find_sets(u) == g.find_sets(v)) {
                ans[l] = 1;
            }

            while(g.snapshot.size() != sz) {
                g.rollback();
            }
            return;
        }

        int mid = (l + r) / 2;
        dfs(id*2,l,mid);
        dfs(id*2+1,mid+1,r);

        while(g.snapshot.size() != sz) {
            g.rollback();
        }
    }

    void solve()
    {
        g.build(); // u < v
        for(int i = 1;i <= q;i++) {
            if(qr[i].type == '+') {
                int u = qr[i].u, v = qr[i].v;
                if(u > v) swap(u,v);

                mp[++cur_id] = {u,v};
                lastpos[cur_id] = i;
                
            }
            else if(qr[i].type == '-') {
                int id = qr[i].id;

                pii edge = mp[id];

                // l -> i - 1;
                int l = lastpos[id], r = i - 1; 

                update(1,1,q,l,r,edge);
                // process

                mp[id] = {0,0};
            }
            else if(qr[i].type == '?') {
                int u = qr[i].u, v = qr[i].v;
                if(u > v) swap(u,v);
                askqueries[i] = {u,v};
            }
        }

        for(auto edge:mp) {
            int st = lastpos[edge.fi];
            if(edge.se.se == 0 || edge.se.fi == 0) continue;
            // cout << edge.se.fi << ' ' << edge.se.se << '\n';
            update(1,1,q,st,q,edge.se);
        }

        dfs(1,1,q);
        for(int i = 1;i <= q;i++) {
            if(qr[i].type == '?') cout << ans[i] << '\n';
        }
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
    cin >> n >> q;
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].type;
        if(qr[i].type == '+' || qr[i].type == '?') {
            cin >> qr[i].u >> qr[i].v;
        }
        else cin >> qr[i].id;
    }

    sol::solve();
    // if(subtask2::checksub2()) subtask2::solve();
    // else subtask1::solve();
    return 0;
}