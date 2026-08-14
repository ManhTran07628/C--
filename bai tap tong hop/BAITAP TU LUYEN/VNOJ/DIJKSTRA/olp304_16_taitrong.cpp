#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e9
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,s,t;
int dist[MM];
vector<pii> adj[MM];
struct Node{int u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};

void dijkstra()
{
    // fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({s,oo});
    dist[s] = oo;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] > U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[v] < min(dist[u],w)) {
                dist[v] = min(dist[u],w);
                q.push({v,dist[v]});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "TAITRONG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    cout << dist[t];
    return 0;
}