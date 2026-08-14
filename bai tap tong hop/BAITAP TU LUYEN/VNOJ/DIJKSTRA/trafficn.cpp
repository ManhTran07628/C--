#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int T,n,m,k,s,t;
ll dist[MM][2];
struct Edge{ll v,w,type;};
vector<Edge> adj[MM];
struct Node{ll u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};


void dijkstra()
{
    // fill(dist+1,dist+n+1,oo);
    for(int i = 1;i <= n;i++)
        dist[i][0] = dist[i][1] = oo;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({s,0});
    dist[s][0] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u][1] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.v, w = X.w, type = X.type;
            if(!type) { // khong phai duong dac biet
                if(dist[v][0] > dist[u][0] + w) {
                    dist[v][0] = dist[u][0] + w;
                    q.push({v,dist[v][0]});
                }
                if(dist[v][1] > dist[u][1] + w) {
                    dist[v][1] = dist[u][1] + w;
                    q.push({v,dist[v][1]});
                }
            }
            else {
                if(dist[v][1] > dist[u][0] + w) {
                    dist[v][1] = dist[u][0] + w;
                    q.push({v,dist[v][1]});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> k >> s >> t;
    for(int i = 1;i <= n;i++)
        adj[i].clear();

    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w,0});
    }
    for(int i = 1;i <= k;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w,1});
        adj[v].push_back({u,w,1});
    }

    dijkstra();
    if(dist[t][0] == oo && dist[t][1] == oo) cout << -1;
    else cout << min(dist[t][0],dist[t][1]);
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}