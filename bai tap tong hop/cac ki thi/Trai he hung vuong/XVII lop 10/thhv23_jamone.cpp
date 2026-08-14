#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll> 
const int MM = 1e3 + 7;
int n,m,k;
vector<pii> adj[MM];
struct Edge{int u,v,p,diff;};
vector<Edge> edges;
vector<int> late;
ll dist[MM];
struct Node{int u; ll dist_u;};
struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};

void dijkstra(int s)
{
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> qr;
    qr.push({s,0});
    dist[s] = 0;
    while(!qr.empty()) {
        Node U = qr.top(); qr.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto N:adj[u]) {
            int v = N.fi, p = N.se;
            if(dist[v] > dist[u] + p) {
                dist[v] = dist[u] + p;
                qr.push({v,dist[v]});
            }
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
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v,p,q; cin >> u >> v >> p >> q;
        edges.push_back({u,v,p,q - p});
        late.push_back(q - p);
    }
    sort(edges.begin(),edges.end(),[] (Edge a, Edge b){return a.diff < b.diff;});
    sort(late.begin(),late.end());
    late.erase(unique(late.begin(),late.end()),late.end());
    while(k--) {
        int s,t; cin >> s >> t;
        int i = 0;
        ll res = oo;
        for(auto D:late) {
            for(;i < edges.size() && edges[i].diff <= D;i++) {
                int u = edges[i].u, v = edges[i].v, p = edges[i].p;
                adj[u].push_back({v,p});
                adj[v].push_back({u,p});
            }
            dijkstra(s);
            res = min(res,dist[t] + D);
            // cout << dist[3] << ' ' << D << '\n';
        }
        cout << res << '\n';

        for(int i = 1;i <= n;i++)
            adj[i].clear();
    }   
    
    return 0;
}