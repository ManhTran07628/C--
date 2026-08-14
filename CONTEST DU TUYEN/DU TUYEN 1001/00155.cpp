#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5;
int n;
ll dist[MM + 7];
struct dl{ll u,d,t;};
vector<dl> adj[MM + 7];
struct Node{ll u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};
priority_queue<Node,vector<Node>,cmp> q;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        ll a,b,d,t; cin >> a >> b >> d >> t;
        adj[a].push_back({b,d,t});
        adj[b].push_back({a,d,t});
    }
    fill(dist+1,dist+n+1,oo);
    for(int i = 1;i <= n;i++) {
        if(adj[i].size() == 1) {
            q.push({i,0});
            dist[i] = 0;
        }
    }
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            ll v = X.u, d = X.d, t = X.t;
            if(dist[u] + d <= t && dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                q.push({v,dist[v]});
            }
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++) {
        res += (dist[i] != oo);
        // cout << i << ' ' << dist[i] << '\n';
    }
    cout << res;
    return 0;
}
