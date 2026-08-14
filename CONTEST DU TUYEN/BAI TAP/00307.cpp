#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int sz = 1e5;
int n,x,m1,m2,s,t;
ll dist[MM];
vector<pii> adj[MM];

struct Node{int u; ll dist_u;};
struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;};};

void dijkstra()
{
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({s,0});
    fill(dist+1,dist+MM,oo);
    dist[s] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(U.dist_u > dist[u]) continue;
        for(auto N:adj[u]) {
            int v = N.fi, w = N.se;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({v,dist[v]});
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
    cin >> n >> x;
    cin >> m1;
    for(int i = 1;i <= m1;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cin >> m2;
    for(int i = 1;i <= m2;i++) {
        int u,v,w; cin >> u >> v >> w; 
        u += sz, v += sz;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int u = 1;u <= n;u++) {
        int v = u + sz;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }
    cin >> s >> t;
    t += sz;
    dijkstra();
    if(dist[t] == oo) cout << -1;
    else cout << dist[t];
    return 0;
}