#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,vis[MM];
ll dist1[MM],dist2[MM];
struct Edge{int v; ll w;};
vector<Edge> adj[MM],Radj[MM];
struct Node{int u; ll dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};

void dijkstra(ll dist[],vector<Edge> adj[])
{
    fill(dist+1,dist+n+1,oo);
    dist[1] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.v; ll w = X.w;
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
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        Radj[v].push_back({u,w});
    }
    dijkstra(dist1,adj);
    dijkstra(dist2,Radj);
    for(int i = 2;i <= n;i++) {
        if(dist1[i] != oo && dist2[i] != oo) {
            cout << dist1[i] + dist2[i] << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}