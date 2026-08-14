#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e5+7;
int n,m,sta[MM],L = 0, R = oo,dist[MM];
struct Edge{int u,t,c;};
vector<Edge> adj[MM];
vector<pii> sp[MM];
struct Node{int u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {
        return a.dist_u > b.dist_u;
    }
};

void dijkstra()
{
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    fill(dist + 1,dist + n + 1,oo);
    dist[1] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.u, c = X.c, t = X.t;
            if(dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
                sp[v].clear();
                sp[ v ].push_back({u, c});
                q.push({v,dist[v]});
            }
            else if(dist[v] == dist[u] + t) sp[ v ].push_back({u, c});
        }
    }
}

bool check(int lim)
{
    queue<pii> q;
    q.push({n,lim});
    while(!q.empty()) {
        int u = q.front().fi, cur_energy = q.front().se; q.pop();
        if(u == 1) return 1;
        for(auto X:sp[u]) {
            int v = X.fi, c = X.se;

            
            if(cur_energy - c >= 0) {
                int new_energy = cur_energy - c;
                if(sta[v]) new_energy = lim;
                q.push({v,new_energy});
            }
        }
    }
    return 0;
}

void solve()
{
    int ans = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
        // cout << mid << '\n';
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> sta[i];
    cin >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,t,c;
        cin >> u >> v >> t >> c;
        adj[u].push_back({v,t,c});
        adj[v].push_back({u,t,c});
        L = min(L,c);
    }
    dijkstra();
    solve();
    return 0;
}