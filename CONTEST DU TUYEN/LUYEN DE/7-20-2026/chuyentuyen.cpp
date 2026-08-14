#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,m,k,p[MM];
vector<pii> adj[MM];

struct Edge{int u,v,c;};
vector<Edge> edges;

struct Node{ll u,dist_,cur_state;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

namespace subtask1
{
    ll d[2007][4007];

    void dijkstra()
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= k + 3;j++) 
                d[i][j] = oo;

        d[1][0] = 0;
        priority_queue<Node,vector<Node>,cmp> q;
        q.push({1,0,0});
        while(!q.empty()) {
            Node N = q.top(); q.pop();
            int u = N.u, cur_state = N.cur_state;
            if(N.dist_ > d[u][cur_state]) continue;
            for(auto U:adj[u]) {
                int v = U.fi, nxt_state = U.se;
                ll new_cost = N.dist_ + (nxt_state == cur_state ? 0 : p[nxt_state]);
                if(d[v][nxt_state] > new_cost) {
                    d[v][nxt_state] = new_cost;
                    q.push({v,new_cost,nxt_state});
                }
            }
        }
    }

    void solve()
    {
        dijkstra();
        ll res = oo;
        for(int i = 1;i <= k;i++) res = min(res,d[n][i]);
        cout << (res == oo ? -1 : res);
    }   
}

namespace subtask2
{
    ll d[MM] = {};

    void dijk()
    {
        for(int i = 1;i <= n;i++) d[i] = oo;
        d[1] = 0;
        priority_queue<Node,vector<Node>,cmp> q;
        q.push({1,0,0});
        while(!q.empty()) {
            Node N = q.top(); q.pop();
            int u = N.u, cur_type = N.cur_state;
            if(N.dist_ > d[u]) continue;
            for(auto U:adj[u]) {
                int v = U.fi, type = U.se;
                ll new_cost = N.dist_ + (cur_type == type ? 0 : p[type]);
                if(d[v] > new_cost) {
                    d[v] = new_cost;
                    q.push({v,d[v]});
                }
            }
        }
    }

    void solve()
    {
        dijk();
        cout << (d[n] == oo ? -1 : d[n]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) cin >> p[i];
    for(int i = 1;i <= m;i++) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
        edges.push_back({u,v,c});
    }
    // subtask1::solve();
    if(n <= 2000 && m <= 4000) subtask1::solve();
    else subtask2::solve();
    return 0;
}