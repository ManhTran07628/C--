#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,m,d1[MM],visited[MM],d2[MM];
vector<pair<int,int>> adj[MM];
struct edge{
    int u,v,w;
} E[MM];

struct Node{ // luu dinh va duong di ngan nhat tu dinh a den b
    int u, Dist_u;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

     
void dijkstra(int *d,int s)
{
    memset(visited,0,sizeof(visited));
    fill(d+1,d+n+1,oo);
    priority_queue<Node, vector<Node>,cmp> q;
    q.push({s,0});
    d[s] = 0;
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u;
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto [v,w]:adj[u]) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({v,d[v]});
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
        cin >> E[i].u >> E[i].v >> E[i].w;
        adj[E[i].u].push_back({E[i].v,E[i].w});
        adj[E[i].v].push_back({E[i].u,E[i].w});
    }
    dijkstra(d1,1);
    dijkstra(d2,n);
    int ans = oo;
    for(int i = 1;i <= m;i++) {
        int u = E[i].u, v = E[i].v, w = E[i].w;
        int path1 = d1[u] + d2[v] + w;
        int path2 = d1[v] + d2[u] + w;
        if(path1 != d1[n]) ans = min(ans,path1);
        if(path2 != d1[n]) ans = min(ans,path2);
    }
    cout << ans;
    return 0;
}