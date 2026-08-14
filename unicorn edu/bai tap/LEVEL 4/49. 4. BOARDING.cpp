#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m,p;
ll dist[MM][2]; // 0 chan   1 le
vector<pii> adj[MM],Nadj[MM];
struct Node{ll u,dist_u,state;};

struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};

void init()
{
    cin >> n >> m >> p;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        Nadj[v].push_back({u,w});
    }
}

void dijkstra()
{
    for(int i = 1;i <= n;i++)
        dist[i][0] = dist[i][1] = oo;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,0});
    dist[1][0] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u, state = U.state;
        if(dist[u][state] < U.dist_u) continue;

        if(dist[u][state ^ 1] > dist[u][state] + p) {
            dist[u][state ^ 1] = dist[u][state] + p;
            q.push({u,dist[u][state ^ 1],state ^ 1});
        }

        // chan
        if(state == 0) {
            for(auto X:adj[u]) {
                int v = X.fi, w = X.se;
                int new_state = (state + 1) % 2;
                if(dist[v][new_state] > dist[u][state] + w) {
                    dist[v][new_state] = dist[u][state] + w;
                    q.push({v,dist[v][new_state],new_state});
                }
            }
        }

        // le
        if(state == 1) {
            for(auto X:Nadj[u]) {
                int v = X.fi, w = X.se;
                int new_state = (state + 1) % 2;
                if(dist[v][new_state] > dist[u][state] + w) {
                    dist[v][new_state] = dist[u][state] + w;
                    q.push({v,dist[v][new_state],new_state});
                }
            }
        }


    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    dijkstra();
    // for(int i = 1;i <= n;i++) cout << i << ' ' << dist[i][0] << ' ' << dist[i][1] << '\n';
    ll res = min(dist[n][0],dist[n][1]);
    cout << (res == oo ? -1 : res);
    return 0;
}