#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;
ll d[MM],danger[MM];
struct Edge{ll v,p,w;};
vector<Edge> adj[MM];

struct Node{ll u,dist_u;};
struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};

void dijkstra()
{
    priority_queue<Node,vector<Node>,cmp> q;
    for(int i = 1;i <= n;i++) danger[i] = oo;
    q.push({1,0});
    danger[1] = 0;
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u;
        if(danger[u] < N.dist_u) continue;
        for(auto U:adj[u]) {
            int v = U.v;
            ll w = U.w, p = U.p;
            if(danger[v] > max(danger[u],p)) {
                danger[v] = max(danger[u],p);
                q.push({v,danger[v]});
            }
        }
    }
}

void SP()
{
    priority_queue<Node,vector<Node>,cmp> q;
    for(int i = 1;i <= n;i++) d[i] = oo;
    q.push({1,0});
    d[1] = 0;
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u;
        if(d[u] < N.dist_u) continue;
        for(auto U:adj[u]) {
            int v = U.v;
            ll w = U.w, p = U.p;
            if(max(danger[u],p) <= danger[n]) {
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    q.push({v,d[v]});
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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll u,v,p,w; cin >> u >> v >> p >> w;
        adj[u].push_back({v,p,w});
        adj[v].push_back({u,p,w});
    }
    dijkstra();
    SP();
    // for(int i = 1;i <= n;i++) cout << i << ' ' << d[i] << '\n';
    cout << danger[n] << ' ' << d[n];
    return 0;
}