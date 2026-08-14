#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,q,vis[MM][2];
ll dist[MM][2];
vector<pii> adj[MM];
struct Node{ll u,dist_u,type;};
struct cmp
{
    bool operator() (Node a, Node b) {return a.dist_u > b.dist_u;}
};


void solve()
{
    int s,t; cin >> s >> t;

    // cout << dist[1][0];
    cout << min(dist[s][0],dist[s][1] + t) << '\n';

}


void dijkstra()
{
    for(int i = 1;i <= n;i++) {
        dist[i][0] = dist[i][1] = oo;
        vis[i][0] = vis[i][1] = 0;
    }
    
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,0});
    dist[1][0] = dist[1][1] = 0;

    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(vis[u][ U.type ]) continue;
        vis[u][ U.type ] = 1;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[v][0] > dist[u][0] + w) {
                dist[v][0] = dist[u][0] + w;
                q.push({v,dist[v][0],0});
            }
            
            if(dist[v][1] > dist[u][0]) {
                dist[v][1] = dist[u][0];
                q.push({v,dist[v][1],1});
            }

            if(dist[v][1] > dist[u][1] + w) {
                dist[v][1] = dist[u][1] + w;
                q.push({v,dist[v][1],1});
            }
            
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijkstra();
    // solve();
    while(q--) {
        solve();
    }
    return 0;
}