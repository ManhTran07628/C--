#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
const int MOD = 1e9+7;
ll n,m,dist[MM];
ll vis[MM],nums[MM],minroute[MM],maxroute[MM];
vector<pair<ll,ll>> adj[MM];
struct Node{
    ll u,dist_u;
};

struct cmp{
    bool operator() (Node &a, Node &b) {
        return a.dist_u > b.dist_u;
    }
};

void dijkstra(int x)
{
    fill(dist+1,dist+n+1,oo);
    fill(minroute+1,minroute+n+1,oo);
    minroute[x] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({x,0});
    nums[x] = 1;
    dist[x] = 0;
    while(!q.empty()) {
        Node E = q.top(); q.pop();
        int u = E.u;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto N:adj[u]) {
            int v = N.first, w = N.second;
            if(dist[v] > dist[u] + w) {
                nums[v] = nums[u];
                dist[v] = dist[u] + w;
                maxroute[v] = maxroute[u]+1;
                minroute[v] = minroute[u]+1;
                q.push({v,dist[v]});
            }
            else if(dist[v] == dist[u] + w) {
                nums[v] = (nums[v] + nums[u]) % MOD;
                maxroute[v] = max(maxroute[v],maxroute[u]+1);
                minroute[v] = min(minroute[v],minroute[u]+1);
            }
        }
    }
}

void init()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
}


void solve()
{
    dijkstra(1);
    cout << dist[n] << ' ' << nums[n] << ' ' << minroute[n] << ' ' << maxroute[n];
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}