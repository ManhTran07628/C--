#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;
ll dist1[MM],dist2[MM],dp[MM];
struct Edge{int u;ll P,Q;};
vector<Edge> adj[MM],Nadj[MM];

struct Edgelist{int u,v;ll P,Q;};
vector<Edgelist> edges;

struct Node{int u; ll dist_u;};
struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};

void dijkstra(ll dist[],int type)
{
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({n,0});
    fill(dist+1,dist+n+1,oo);
    dist[n] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto N:adj[u]) {
            int v = N.u; ll P = N.P, Q = N.Q;
            if(type == 1 && dist[v] > dist[u] + P) {
                dist[v] = dist[u] + P;
                q.push({v,dist[v]});
            }
            if(type == 2 && dist[v] > dist[u] + Q) {
                dist[v] = dist[u] + Q;
                q.push({v,dist[v]});
            }
        }
    }
}

void dijkstra_newpath()
{
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    fill(dp+1,dp+n+1,oo);
    dp[1] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dp[u] < U.dist_u) continue;
        for(auto N:Nadj[u]) {
            int v = N.u; ll P = N.P;
            if(dp[v] > dp[u] + P) {
                dp[v] = dp[u] + P;
                q.push({v,dp[v]});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll u,v,P,Q; cin >> u >> v >> P >> Q;
        adj[v].push_back({u,P,Q});
        edges.push_back({u,v,P,Q});
    }
    dijkstra(dist1,1);
    dijkstra(dist2,2);
    for(auto N:edges) {
        int u = N.u, v = N.v; ll P = N.P, Q = N.Q;
        int cnt = (dist1[u] != dist1[v] + P) + (dist2[u] != dist2[v] + Q);
        Nadj[u].push_back({v,cnt,cnt});
    }
    dijkstra_newpath();
    cout << dp[n];
    return 0;
}