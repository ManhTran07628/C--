#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
int n,m,k;
vector<pii> adj[MM];
struct Node{ll u,dist_,ticket_left;};
struct cmp{bool operator() (Node a,Node b) {return a.dist_ > b.dist_;}};

ll d[MM][11];

void dijk()
{
    for(int i = 1;i <= n;i++)
        for(int j = 0;j <= k;j++)
            d[i][j] = oo;

    d[1][k] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0,k});
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u, ticket_left = N.ticket_left;
        if(d[u][ticket_left] < N.dist_) continue;

        for(auto U:adj[u]) {
            int v = U.fi, w = U.se;
            if(d[v][ticket_left] > d[u][ticket_left] + w) {
                d[v][ticket_left] = d[u][ticket_left] + w;
                q.push({v,d[v][ticket_left],ticket_left});
            }

            if(ticket_left > 0 && d[v][ticket_left - 1] > d[u][ticket_left]) {
                d[v][ticket_left - 1] = d[u][ticket_left];
                q.push({v,d[v][ticket_left - 1],ticket_left - 1});
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
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijk();
    ll res = oo;
    for(int i = 0;i <= k;i++) res = min(res,d[n][i]);
    cout << (res == oo ? -1 : res);
    return 0;
}