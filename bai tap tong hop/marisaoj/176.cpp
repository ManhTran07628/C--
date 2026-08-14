#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,m,k,visited[MM][6],dist[MM][6];
vector<pair<int,int>> adj[MM];

struct Node{
    int u,Dist_u,k;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

void dijkstra()
{
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= k;j++)
            dist[i][j] = oo;
    }
    priority_queue<Node,vector<Node>,cmp> q;
    dist[1][0] = 0;
    q.push({1,0,0});
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u,D = top.Dist_u,ope = top.k;
        if(visited[u][ope]) continue;
        visited[u][ope] = 1;
        for(auto [v,w]: adj[u]) {
            if(ope < k) {
                if(dist[v][ope+1] > D) {
                    dist[v][ope+1] = D;
                    q.push({v,dist[v][ope+1],ope+1});
                }
            }
            if(dist[v][ope] > D + w) {
                dist[v][ope] = D + w;
                q.push({v,dist[v][ope],ope});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    int ans = oo;
    for(int i = 0;i <= k;i++) {
        ans = min(ans,dist[n][i]);
        // cout << dist[n][i] << '\n';
    }
    cout << (ans != oo ? ans:-1);
    return 0;
}