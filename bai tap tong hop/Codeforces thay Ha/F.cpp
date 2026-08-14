#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 2e5+7;
ll n,m;
ll vis[MM],min_p[MM],dist[MM];
vector<pair<ll,ll>> adj_p[MM];
struct Edge{
    ll v,p,w;
};
vector<Edge> adj_w[MM];

struct Node{
    ll u,weight,p;
};

struct cmp{
    bool operator() (Node &a, Node &b) {
        return a.weight > b.weight;
    }
};

void dijk1(ll dist[],vector<pair<ll,ll>> adj[],int st)
{
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0,0});
    dist[st] = 0;
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        ll u = N.u, prev_w = N.weight;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto E: adj[u]) {
            ll v = E.first, cur_w = E.second;
            if(dist[v] > max(prev_w,cur_w)) {
                dist[v] = max(prev_w,cur_w);
                q.push({v,dist[v],0});
            }
        }
    }
}

void dijk2(ll dist[],vector<Edge> adj[],int st)
{
    ll mp = min_p[n];
    fill(dist+1,dist+n+1,oo);
    memset(vis,0,sizeof(vis));
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0,0});
    dist[st] = 0;
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        ll u = N.u, prev_p = N.p;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto E:adj[u]) {
            ll v = E.v, cur_p = E.p, cur_w = E.w;
            if(max(cur_p,prev_p) <= mp && dist[v] > dist[u] + cur_w) {
                dist[v] = dist[u] + cur_w;
                q.push({v,dist[v],max(cur_p,prev_p)});
            }   
        }
    }
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll u,v,p,w;
        cin >> u >> v >> p >> w;
        adj_p[u].push_back({v,p});
        adj_p[v].push_back({u,p});
        adj_w[u].push_back({v,p,w});
        adj_w[v].push_back({u,p,w});
    }
    dijk1(min_p,adj_p,1);
    dijk2(dist,adj_w,1);
    cout << min_p[n] << ' ' << dist[n];
    return 0;
}