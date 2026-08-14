#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,k,x,vis[MM],costQ[MM],costV[MM],costN[MM],costK[MM],ans = oo;
struct Edge{
    int v,w; // luu canh trong so
};
vector<vector<Edge>> bike,walk,rev_n,rev_k;

struct Node{
    int u,dist_u; // canh va duong di
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.dist_u > b.dist_u;
    }
};

void dijkstra(vector<vector<Edge>> &adj,int d[],int st)
{
    fill(d+1,d+n+1,oo);
    memset(vis,0,sizeof(vis));
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    d[st] = 0;
    while(!q.empty()) {
        Node E = q.top(); q.pop();
        int u = E.u;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto x: adj[u]) {
            int v = x.v,w = x.w;
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
    cin >> n >> m >> k >> x;
    bike.resize(n+1); walk.resize(n+1); rev_n.resize(n+1); rev_k.resize(n+1);
    for(int i = 1;i <= m;i++) {
        int u,v,a,b;
        cin >> u >> v >> a >> b;
        walk[u].push_back({v,a});
        bike[u].push_back({v,b});
        rev_n[v].push_back({u,b});
        rev_k[v].push_back({u,a});
    }
    dijkstra(walk,costV,1);
    dijkstra(bike,costQ,1);
    dijkstra(rev_n,costN,n);
    dijkstra(rev_k,costK,k);
    for(int i = 1;i <= n;i++) {
        if(costQ[i] != oo && costV[i] != oo && costN[i] != oo && costK[i] != oo) {
            int v_path = costQ[i] + costK[i];
            int q_path = costQ[i] + costN[i];
            if(v_path <= x && q_path < ans) ans = q_path;
        }
    }
    cout << (ans != oo ? ans : -1);
    return 0;
}
