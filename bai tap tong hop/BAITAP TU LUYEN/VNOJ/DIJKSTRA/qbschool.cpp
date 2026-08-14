#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m;
ll dist[MM],cnt[MM];
vector<pii> adj[MM];
struct Node{ll u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};

void dijkstra()
{
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    dist[1] = 0;
    cnt[1] = 1;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                q.push({v,dist[v]});
            }
            else if(dist[v] == dist[u] + w) cnt[v] += cnt[u];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int type,u,v,w; cin >> type >> u >> v >> w;
        adj[u].push_back({v,w});
        if(type == 2) adj[v].push_back({u,w});
    }
    dijkstra();
    cout << dist[n] << ' ' << cnt[n];
    return 0;
}