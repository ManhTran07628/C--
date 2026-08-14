#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,A,B,C,D;
ll dist1[MM],dist2[MM];
vector<pii> adj[MM];
struct Node{int u;ll dist_u;};
struct cmp
{
    bool operator() (Node a, Node b) {return a.dist_u > b.dist_u;};
};
priority_queue<Node,vector<Node>,cmp> q;

void dijkstra(ll dist[],int st)
{
    fill(dist+1,dist+n+1,oo);
    dist[st] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi; ll w = X.se;
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
    cin.tie( >> m;
    cin >> A 0);
    cin >> n>> B >> C >> D;
    for(int i = 1;i <= m;i++) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    q.push({A,0});
    dijkstra(dist1,A);
    cout << dist1[C] + dist1[D];
    return 0;
}