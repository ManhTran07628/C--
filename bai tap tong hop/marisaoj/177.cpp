#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
const int MOD = 1e9+7;
int n,m,k,visited[MM][11],dist[MM][11];
vector<pair<int,int>> adj[MM];

struct Node{
    int u,Dist_u,w;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

void dijkstra()
{
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= 10;j++) 
            dist[i][j] = oo;
    }
    // cout << dist[1][0] << ' ';
    dist[1][0] = 0; // j = 0 : van dang o a    j > 0: j dang o b va co duong di b -> c
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,0});
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int a = top.u, Dist_a = top.Dist_u, w = top.w;
        if(visited[a][w]) continue;
        visited[a][w] = 1;
        for(auto [b,j]:adj[a]) {
            if(w == 0) {
                if(dist[b][j] > Dist_a) {
                    dist[b][j] = Dist_a;
                    q.push({b,dist[b][j],j});
                }
            }
            else {
                int ac = w*j;
                if(dist[b][0] > Dist_a + ac) {
                    dist[b][0] = Dist_a + ac;
                    q.push({b,dist[b][0],0});
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
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    cout << (dist[n][0] != oo ? dist[n][0] : -1);
    return 0;
}