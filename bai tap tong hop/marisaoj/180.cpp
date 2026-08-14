#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,m,dist[MM][2],visited[MM];
vector<pair<int,int>> adj[MM];

struct Node{ // luu dinh va duong di ngan nhat tu dinh a den b
    int u, Dist_u;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};
// dist[i][0] : chua su dung
// dist[i][1] : da su dung
     
void dijkstra()
{
    for(int i = 2;i <= n;i++) {
        dist[i][0] = oo;
        dist[i][1] = 0;
    }
    priority_queue<Node, vector<Node>,cmp> q;
    q.push({1,0});
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u,dist_u = top.Dist_u;
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto [v,w]: adj[u]) {
            if(dist[v][0] - dist[v][1] > dist[u][0] + w - max(w,dist[u][1])) {
                dist[v][0] = dist[u][0] + w;
                dist[v][1] = max(w,dist[u][1]);
                q.push({v,dist[v][0]});
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
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dijkstra();
    int ans = dist[n][0] - dist[n][1];
    cout << (ans != oo ? ans : -1);
    return 0;
}