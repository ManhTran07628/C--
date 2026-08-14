#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MM = 1e3+7;
const int lim = 1e6;
int n,m,dist[MM],vis[MM],oo = 1e9;
struct edge{int u,c,f;}; vector<edge> adj[MM];
struct Node{int u,dist_u;}; 
struct cmp
{
    bool operator() (Node &a,Node &b)
    {
        return a.dist_u > b.dist_u;
    }
};

void load_graph()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b,c,f;
        cin >> a >> b >> c >> f;
        adj[a].push_back({b,c,f});
        adj[b].push_back({a,c,f});
    }
}

void dijkstra(int st,int F)
{
    memset(vis,0,sizeof(vis));
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    fill(dist+1,dist+n+1,oo);
    dist[1] = 0;
    while(!q.empty()) {
        auto N = q.top(); q.pop();
        int u = N.u;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto E:adj[u]) {
            int v = E.u, f = E.f, c = E.c;
            if(f < F) continue;
            if(dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                q.push({v,dist[v]});
            }
        }
    }
}

void solve()
{
    double ans = 0;
    for(int i = 1;i <= 1000;i++) {
        dijkstra(1,i);
        // cout << dist[n] << '\n';
        if(dist[n] != oo) {
            ans = max(ans, (double)i / dist[n] * lim);
        }
    }
    cout << (int)ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "pump"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    load_graph();
    solve();
    return 0;
}