#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e12
#define pii pair<int,int>
const int MM = 1e3+7;
int t,n,m;
ll dist[MM][MM];
vector<pii> adj[MM];
struct Node{int u;ll dist_u;};
struct cmp
{
    bool operator() (Node a, Node b) {return a.dist_u > b.dist_u;}
};
priority_queue<Node,vector<Node>,cmp> q;

void dijkstra(int st)
{
    for(int i = 1;i <= n;i++)
        dist[st][i] = oo;
        
    q.push({st,0});
    dist[st][st] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[st][u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[st][v] > dist[st][u] + w) {
                dist[st][v] = dist[st][u] + w;

                q.push({v,dist[st][v]});
            }
        }
    }
}


void solve()
{
    cin >> n >> m;
    
    for(int i = 1;i <= m;i++) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
    }
    
    for(int i = 1;i <= n;i++) dijkstra(i);
    
    for(int i = 1;i <= n;i++) {
        ll res = oo;
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            res = min(res,dist[i][j] + dist[j][i]);
        }
        cout << (res == oo ? -1 : res) << '\n';
        adj[i].clear();
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}