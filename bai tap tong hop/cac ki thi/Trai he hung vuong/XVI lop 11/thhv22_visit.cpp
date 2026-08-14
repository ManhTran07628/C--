#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
int n,m,k,q,p[MM];
struct Edge{ll u,v,w;};
vector<Edge> edges;
vector<pii> adj[MM];

struct Node{ll u,dist_;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};


namespace subtask1
{
    ll d[MM] = {};
    void dijkstra(int st)
    {
        for(int i = 1;i <= n;i++) d[i] = oo;
        priority_queue<Node,vector<Node>,cmp> q;
        q.push({st,0});
        d[1] = 0;
        while(!q.empty()) {
            Node N = q.top(); q.pop();
            int u = N.u;
            if(N.dist_ > d[u]) continue;
            for(auto U:adj[u]) {
                int v = U.fi, w = U.se;
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    q.push({v,d[v]});
                }
            }
        }
    }

    void solve()
    {
        dijkstra(1);
        cout << d[ p[1] ];
    }
}

namespace subtask2
{
    int par[MM] = {};
    
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

    void solve()
    {
        for(int i = 1;i <= n;i++) par[i] = i;
        ll mst = 0;
        sort(edges.begin(),edges.end(), [] (Edge a,Edge b){return a.w < b.w;});
        for(auto E:edges) {
            if(!Unite(E.u,E.v)) continue;
            mst += E.w;
        }
        cout << mst;
    }
}

namespace sol
{
    ll d[MM] = {}, near[MM] = {};

    int par[MM] = {};
    
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

    void dijkstra()
    {
        for(int i = 1;i <= n;i++) d[i] = oo;
        priority_queue<Node,vector<Node>,cmp> qr;
        for(int i = 1;i <= k;i++) {
            if(p[i] > 1) {
                d[ p[i] ] = 0;
                qr.push({p[i],0});
                near[ p[i] ] = p[i];
            }
        }
        qr.push({1,0});
        d[1] = 0;
        near[1] = 1;
        while(!qr.empty()) {
            Node N = qr.top(); qr.pop();
            int u = N.u;
            if(N.dist_ > d[u]) continue;
            for(auto U:adj[u]) {
                int v = U.fi, w = U.se;
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    near[v] = near[u];
                    qr.push({v,d[v]});
                }
            }
        }
    }

    vector<Edge> new_edges;

    void solve()
    {
        for(int i = 1;i <= n;i++) par[i] = i;
        dijkstra();
        for(auto E:edges) {
            ll u = E.u, v = E.v, w = E.w;
            if(near[u] != near[v]) {
                new_edges.push_back({near[u],near[v],d[u] + d[v] + w});
            }
        }

        sort(new_edges.begin(),new_edges.end(), [] (Edge a,Edge b){return a.w < b.w;});

        ll mst = 0;
        for(auto E:new_edges) {
            if(!Unite(E.u,E.v)) continue;
            mst += E.w;
        }
        cout << mst;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "aaaadada"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    cin >> k;
    for(int i = 1;i <= k;i++) cin >> p[i];
    sol::solve();
    // if(k == 1) subtask1::solve();
    // else subtask2::solve();
    return 0;
}