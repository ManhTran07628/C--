#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,k,s,t;
ll dist[MM][6];
vector<pii> adj[MM];
struct Node{ll u,dist_u,used;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};

void dijkstra()
{
    for(int i = 1;i <= n;i++)
        for(int j = 0;j <= k;j++)
            dist[i][j] = oo;

    priority_queue<Node,vector<Node>,cmp> q;
    q.push({s,0,0});
    dist[s][0] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u, used = U.used;
        if(dist[u][used] < U.dist_u) continue;
        for(auto X: adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[v][used] > dist[u][used] + w) {  // khong chon
                dist[v][used] = dist[u][used] + w;
                q.push({v,dist[v][used],used});
            }
            if(used + 1 <= k && dist[v][used + 1] > dist[u][used]) { // chon
                dist[v][used + 1] = dist[u][used];
                q.push({v,dist[v][used + 1],used + 1});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> s >> t;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra();
    ll res = oo;
    for(int i = 0;i <= k;i++) 
        res = min(res,dist[t][i]);
    cout << res;
    return 0;
}