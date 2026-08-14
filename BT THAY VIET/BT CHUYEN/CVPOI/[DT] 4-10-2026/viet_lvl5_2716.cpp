#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,m,x;
int h[MM];
struct Edge{int a,b,t;};
vector<Edge> Dash;
vector<pii> adj[MM];

struct Node{ll u,dist_u,cur_height;};
struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};
ll dist[MM][101];

void dijkstra()
{
    priority_queue<Node,vector<Node>,cmp> q;
    for(int i = 1;i <= n;i++)
        for(int j = 0;j <= h[i];j++)
            dist[i][j] = oo;

    q.push({1,0,x});
    dist[1][x] = 0;
    while(!q.empty()) {
        auto U = q.top(); q.pop();
        int u = U.u, cur_height = U.cur_height;
        if(dist[u][cur_height] < U.dist_u) continue;
        
        for(int i = 0;i <= h[u];i++) {
            int need = abs(cur_height - i);
            if(dist[u][i] > dist[u][cur_height] + need) {
                dist[u][i] = dist[u][cur_height] + need;
                q.push({u,dist[u][i],i});
            }
        }

        for(auto N:adj[u]) {
            int v = N.fi, t = N.se;
            int nxt_height = cur_height - t;

            if(0 <= nxt_height && nxt_height <= h[v] && dist[v][nxt_height] > dist[u][cur_height] + t) {
                dist[v][nxt_height] = dist[u][cur_height] + t;
                q.push({v,dist[v][nxt_height],nxt_height});
            }
        }


    }

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "xx"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> x;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= m;i++) {
        int a,b,t; cin >> a >> b >> t;
        Dash.push_back({a,b,t});
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }
    dijkstra();
    map<ll,ll> mp[100000];
    // for(int i = 0;i <= h[1];i++) cout << i << ' ' << dist[1][i] << '\n';
    cout << (dist[n][h[n]] == oo ? -1 : dist[n][h[n]]);
    return 0;
}