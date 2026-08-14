#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<ll,ll>
const int MM = 2e5+7;
int n,k,m,city[MM];
ll dist[MM][1 << 5],res = 0;
vector<pii> adj[MM];

struct Node{ll u,dist_u;};
struct cmp{bool operator() (Node a,Node b){
    return a.dist_u > b.dist_u;
}};


void dijkstra(int mask,priority_queue<Node,vector<Node>,cmp> q)
{
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u][mask] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[v][mask] > dist[u][mask] + w) {
                dist[v][mask] = dist[u][mask] + w;
                q.push({v,dist[v][mask]});
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1;i <= k;i++) cin >> city[i];
    
    for(int i = 1;i <= m;i++) {
        ll u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    for(int mask = 1;mask < (1 << k);mask++)
        for(int i = 1;i <= n;i++) 
            dist[i][mask] = oo;

    for(int i = 1;i <= k;i++) dist[ city[i] ][1 << (i-1)] = 0;

    for(int mask = 1;mask < (1 << k);mask++) {
        for(int smask1 = (mask - 1) & mask;smask1 > 0;smask1 = (smask1 - 1) & mask) {
            int smask2 = mask ^ smask1;
            for(int i = 1;i <= n;i++) {
                ll costA = dist[i][smask1]; if(costA == oo) continue;
                ll costB = dist[i][smask2]; if(costB == oo) continue;
                if(dist[i][mask] > costA + costB)
                    dist[i][mask] = costA + costB;
            }
        }
        priority_queue<Node,vector<Node>,cmp> q;
        for(int i = 1;i <= n;i++)
            if(dist[i][mask] != oo) q.push({i,dist[i][mask]});
        dijkstra(mask,q);
    }
    ll res = oo;
    for(int i = 1;i <= n;i++) res = min(res,dist[i][(1 << k) - 1]);
    cout << res;

    return 0;
}