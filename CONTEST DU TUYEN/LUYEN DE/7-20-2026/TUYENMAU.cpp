#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m,s[MM];
struct Edge{int v,color,w;};
vector<Edge> adj[MM];

struct Node{ll u,dist_,color;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};
ll d[MM];

void dijk()
{
    fill(d+1,d+n+1,oo);
    d[1] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,0});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u, cur_color = N.color;
        if(d[u] < N.dist_) continue;
        for(auto U:adj[u]) {
            int v = U.v, nxt_color = U.color, w = U.w;
            ll cost = d[u] + w + (cur_color == nxt_color ? 0 : s[u]);
            if(d[v] > cost) {
                d[v] = cost;
                q.push({v,d[v],nxt_color});
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
    for(int i = 1;i <= n;i++) cin >> s[i];
    for(int i = 1;i <= m;i++) {
        int u,v,c,w; cin >> u >> v >> c >> w;
        adj[u].push_back({v,c,w});
        adj[v].push_back({u,c,w});
    }
    dijk();
    cout << d[n];
    return 0;
}