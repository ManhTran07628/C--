#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,vis[MM],dis[MM];
struct edge{
    int u,weight;
};
vector<vector<edge>> adj;

struct Node{
    int u,dist_u;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.dist_u > b.dist_u;
    }
};

void dijkstra()
{
    fill(dis+1,dis+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    dis[1] = 0;
    while(!q.empty()) {
        Node x = q.top(); q.pop();
        int u = x.u;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto y:adj[u]) {
            int v = y.u,w = y.weight;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v,dis[v]});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    for(int i = 1;i <= n;i++) {
        cout << (dis[i] != oo ? dis[i] : -1) << '\n';
    }
    return 0;
}