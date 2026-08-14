#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m,a[MM];
ll dist[MM][3][3];
vector<pair<int,int>> adj[MM];

struct Node{ll u,dist_u,vis,state;};
struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};

// 0 - chua lam gi
// 1 - da mua
// 2 - da ban

void dijkstra()
{
    for(int i = 1;i <= n;i++)
        for(int j = 0;j <= 2;j++)
            for(int k = 0;k <= 2;k++)
                dist[i][j][k] = oo;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,0,0});
    q.push({1,a[1],0,1});
    dist[1][0][0] = 0;
    dist[1][0][1] = a[1];
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u, state = U.state, vis = U.vis;
        if(dist[u][state][vis] < U.dist_u) continue;

        for(auto N:adj[u]) {
            int v = N.fi, w = N.se;


            // 0 - chua lam gi
            if(state == 0) {

                // khong lam gi
                if(dist[v][vis][state] > dist[u][vis][state] + w) {
                    dist[v][vis][state] = dist[u][vis][state] + w;
                    q.push({v,dist[v][vis][state],vis,state});
                }

                if(vis == 0 && dist[v][vis + 1][state] > dist[u][vis + 1][state] + w) {
                    dist[v][vis + 1][state] = dist[u][vis + 1][state] + w;
                    q.push({v,dist[v][vis + 1][state],vis + 1,state});
                }

                if(vis == 1 && dist[v][vis + 1][state] > dist[u][vis + 1][state] + w) {
                    dist[v][vis + 1][state] = dist[u][vis + 1][state] + w;
                    q.push({v,dist[v][vis + 1][state],vis + 1,state});
                }

                // mua kim cuong
                if(dist[v][vis][state + 1] > dist[u][vis][state] + w + a[v]) {
                    dist[v][vis][state + 1] = dist[u][vis][state] + w + a[v];
                    q.push({v,dist[v][vis][state + 1],vis,state + 1}); 
                }


            }

            //th2 da mua kim cuong
            if(state == 1) {

                // khong lam gi
                if(dist[v][vis][state] > dist[u][vis][state] + w) {
                    dist[v][vis][state] = dist[u][vis][state] + w;
                    q.push({v,dist[v][vis][state],vis,state});
                }

                if(vis == 0 && dist[v][vis + 1][state] > dist[u][vis + 1][state] + w) {
                    dist[v][vis + 1][state] = dist[u][vis + 1][state] + w;
                    q.push({v,dist[v][vis + 1][state],vis + 1,state});
                }

                if(vis == 1 && dist[v][vis + 1][state] > dist[u][vis + 1][state] + w) {
                    dist[v][vis + 1][state] = dist[u][vis + 1][state] + w;
                    q.push({v,dist[v][vis + 1][state],vis + 1,state});
                }

                // ban kim cuong
                if(dist[v][vis][state + 1] > dist[u][vis][state] + w - a[v]) {
                    dist[v][vis][state + 1] = dist[u][vis][state] + w - a[v];
                    q.push({v,dist[v][vis][state + 1],vis,state + 1}); 
                }

            }

            //th3 da ban kim cuong
            if(state == 2) {

                // khong lam gi
                if(dist[v][vis][state] > dist[u][vis][state] + w) {
                    dist[v][vis][state] = dist[u][vis][state] + w;
                    q.push({v,dist[v][vis][state],vis,state});
                }

                if(vis == 0 && dist[v][vis + 1][state] > dist[u][vis + 1][state] + w) {
                    dist[v][vis + 1][state] = dist[u][vis + 1][state] + w;
                    q.push({v,dist[v][vis + 1][state],vis + 1,state});
                }

                if(vis == 1 && dist[v][vis + 1][state] > dist[u][vis + 1][state] + w) {
                    dist[v][vis + 1][state] = dist[u][vis + 1][state] + w;
                    q.push({v,dist[v][vis + 1][state],vis + 1,state});
                }

            }


        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    ll res = oo;
    // for(int i = 1;i <= n;i++) cout << dist[i][0][0] << ' ' << i << '\n';
    for(int j = 0;j <= 2;j++)
        for(int k = 0;k <= 2;k++) {
            res = min(res,dist[n][j][k]);
            // cout << dist[n][j][k] << ' ' << j << ' ' << k << '\n';
        }
    // cout << dist[2][0][1];
    cout << res;



    return 0;
}