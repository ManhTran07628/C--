#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 2e5+7;
int n,m;
ll dist[MM],beauty[MM];
struct Edge{int v; ll l,c;};
vector<Edge> adj[MM];
struct Node{int u; ll dist_u,beauty;};

struct cmp
{
    bool operator() (Node a, Node b) {return a.dist_u > b.dist_u;}
};


void dijkstra()
{
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    dist[1] = 0;
    q.push({1,0,0});
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.v; ll l = X.l, c = X.c;
            if(dist[v] > dist[u] + l) {
                dist[v] = dist[u] + l;
                beauty[v] = beauty[u] + c;
                q.push({v,dist[v],beauty[v]});
            }
            else if(dist[v] == dist[u] + l) {

                if(beauty[v] < beauty[u] + c) {
                    beauty[v] = beauty[u] + c;
                    q.push({v,dist[v],beauty[v]});
                }

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
        int u,v,l,c;
        cin >> u >> v >> l >> c;
        adj[u].push_back({v,l,c});
        adj[v].push_back({u,l,c});
    }
    dijkstra();
    if(dist[n] == oo) cout << -1;
    else cout << dist[n] << ' ' << beauty[n];
    return 0;
}