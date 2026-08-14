#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 2e5+7;
int n,m,k;
vector<int> adj[MM];
ll dist[MM];
struct Node{int u;ll dist_u;};
struct cmp{
    bool operator() (Node a, Node b) {return a.dist_u < b.dist_u;};
};
priority_queue<Node,vector<Node>,cmp> q;


void dijkstra()
{
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] > U.dist_u) continue;
        for(auto v:adj[u]) {
            if(dist[v] < dist[u] - 1) {
                dist[v] = dist[u] - 1;
                q.push({v,dist[v]});
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
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist+1,dist+n+1,-1);
    for(int i = 1;i <= k;i++) {
        int p,r; cin >> p >> r;
        r = min(r,MM);
        if(dist[p] > r) continue;
        dist[p] = r;
        q.push({p,r});
    }
    dijkstra();
    for(int i = 1;i <= n;i++) {
        cout << (dist[i] != -1 ? 1 : 0);
    }
    return 0;
}
