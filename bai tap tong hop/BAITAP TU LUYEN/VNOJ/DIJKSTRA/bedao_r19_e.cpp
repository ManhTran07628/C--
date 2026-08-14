#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
#define pii pair<int,int>
const int MM = 2e5+7;
int n,m;
ll dist[MM],diff[MM];
struct Edge{int v;ll w,h;};
vector<Edge> adj[MM];
struct Node{int u; ll dist_u,max_h,min_h;};

struct cmp
{
    bool operator() (Node a, Node b) {return a.dist_u > b.dist_u;};
};

void dijkstra()
{
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,-oo,oo});
    dist[1] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X: adj[u]) {
            int v = X.v; ll w = X.w, h = X.h;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ll max_h = max(U.max_h,h);
                ll min_h = min(U.min_h,h);
                diff[v] = max_h - min_h;
                q.push({v,dist[v],max_h,min_h});
            }
            else if(dist[v] == dist[u] + w) {
                
                if(diff[v] < max(U.max_h,h) - min(U.min_h,h)) {
                    ll max_h = max(U.max_h,h);
                    ll min_h = min(U.min_h,h);
                    diff[v] = max_h - min_h;
                    q.push({v,dist[v],max_h,min_h});
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
        int u,v,w,h;
        cin >> u >> v >> w >> h;
        adj[u].push_back({v,w,h});
        adj[v].push_back({u,w,h});
    }
    dijkstra();
    cout << diff[n];
    return 0;
}