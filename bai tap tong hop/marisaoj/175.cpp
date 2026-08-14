#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
const int MOD = 1e9+7;
int n,m,k,visited[MM],dist[MM],min_path = oo,dp[MM];
vector<pair<int,int>> adj[MM];

struct Node{
    int u,Dist_u;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

void dijkstra()
{
    fill(dist+1,dist+n+1,oo);
    dist[1] = 0;
    dp[1] = 1;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u, Dist_u = top.Dist_u;
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto [v,w]:adj[u]) {
            if(dist[v] == dist[u] + w) {
                dp[v] = (dp[v]+dp[u]) % MOD;
            }
            if(dist[v] > dist[u] + w) {
                dp[v] = dp[u] % MOD;
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
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    cout << dp[n];
    return 0;
}