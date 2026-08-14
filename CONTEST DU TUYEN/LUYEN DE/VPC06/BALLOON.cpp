#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
const int MOD = 1e9 + 7;
int n,m;
vector<pii> adj[MM];
struct Edge{int u,v,w,id;};
vector<Edge> edges,new_edges;

struct Node{ll u,dist_;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

ll d[MM],total_weight = 0,cnt[MM],need[MM];

void dijkstra(ll d[], vector<pii> adj[])
{
    for(int i = 0;i <= n;i++) d[i] = oo;
    d[0] = 0;
    cnt[0] = 1;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({0,0});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u;
        if(N.dist_ > d[u]) continue;
        for(auto U:adj[u]) {
            int v = U.fi, w = U.se;
            if(d[v] == d[u] + w) {
                cnt[v] += cnt[u];
                cnt[v] %= MOD;
            }

            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                cnt[v] = cnt[u];
                cnt[v] %= MOD;
                q.push({v,d[v]});
            }
        }
    }
}

struct DSU
{
    int par[MM] = {};

    void build()
    {
        for(int i = 0;i < MM;i++) par[i] = i;
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

namespace subtask1
{
    vector<int> opt;
    ll vis[27] = {}, sp[27] = {};
    vector<pii> g[27];
    ll res = -1;

    void dfs(int u)
    {
        vis[u] = 1;
        for(auto N:g[u]) {
            int v = N.fi;
            if(vis[v]) continue;
            dfs(v);
        }
    }

    bool check()
    {
        for(int i = 0;i <= n;i++) g[i].clear();
        for(int i = 0;i <= n;i++) vis[i] = 0;

        for(auto id:opt) {
            int u = edges[id].u, v = edges[id].v, w = edges[id].w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        dfs(0);
        for(int i = 0;i <= n;i++) if(!vis[i]) return 0;
        
        dijkstra(sp,g);

        for(int i = 0;i <= n;i++) {
            if(sp[i] > d[i]) {
                return 0;
            }
        }

        return 1;
    }

    void Try(int i,ll sum)
    {
        if(i == m) {
            if(opt.size() != n) return;
            if(check()) res = max(res,sum);
            return;
        }

        opt.push_back(i);
        Try(i + 1,sum + edges[i].w);
        opt.pop_back();
        
        Try(i + 1,sum);
    }

    void solve()
    {
        dijkstra(d,adj);
        Try(0,0);
        cout << m - n << ' ' << res;
    }
}

namespace sol
{
    void solve()
    {
        dijkstra(d,adj);
        for(auto E:edges) {
            int u = E.u, v = E.v, w = E.w;
            if(d[u] + w == d[v] || d[v] + w == d[u]) new_edges.push_back(E);
        }
        edges = new_edges;
        new_edges.clear();
        g.build();

        for(auto E:edges) {
            int u = E.u, v = E.v, w = E.w;
            if(d[u] + w == d[v] && cnt[u] == cnt[v]) {
                need[E.id] = 1;
                total_weight += w;
                g.Unite(u,v);
            }
            if(d[v] + w == d[u] && cnt[u] == cnt[v]) {
                need[E.id] = 1;
                total_weight += w;
                g.Unite(u,v);
            }
        }

        sort(edges.begin(),edges.end(), [] (Edge a,Edge b){return a.w > b.w;});
        for(auto E:edges) {
            int u = E.u, v = E.v, w = E.w;
            if(!g.Unite(u,v)) continue;
            total_weight += w;
        }
        cout << m - n << ' ' << total_weight;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BALLOON"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        if(u > v) swap(u,v);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w,i});
    }
    sol::solve();
    return 0;
}