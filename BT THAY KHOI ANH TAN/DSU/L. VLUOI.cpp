#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,ll>
const int MM = 1e3+7;
const int MS = 1e6+7;
int n,m,c[MM][MM],comps = 0,vis[MM][MM],comps_id[MM][MM],dd[MS];
ll cost[MS],weight = 0,dist[MS];
vector<pii> adj[MS];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool validcoord(int x,int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void dfs(int x,int y)
{
    comps_id[x][y] = comps;
    if(c[x][y] != 1) weight += c[x][y];
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if(validcoord(u,v) && !vis[u][v] && c[x][y] == c[u][v]) {
            dfs(u,v);
        }
    }
}

void add_comps(int x,int y)
{
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if(validcoord(u,v) && !vis[u][v]) {
            if(comps_id[x][y] != comps_id[u][v]) {
                int a = comps_id[x][y], b = comps_id[u][v];
                adj[a].push_back({b,cost[ b ]});
                adj[b].push_back({a,cost[ a ]});
            }
            else add_comps(u,v);
        }
    }
}

struct Node{int u;ll dist_u;};

struct cmp
{
    bool operator() (Node a,Node b)
    {
        return a.dist_u > b.dist_u;
    }
};

void dijkstra(int vis[])
{
    fill(dist+1,dist+comps+1,oo);
    dist[1] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,0});
    while(!q.empty()) {
        Node Top = q.top(); q.pop();
        int u = Top.u;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto X:adj[u]) {
            int v = X.fi; ll weight = X.se;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                q.push({v,dist[v]});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) 
            if(!vis[i][j]) {
                comps++;
                dfs(i,j);
                cost[ comps ] = weight;
                weight = 0;
            }
        
    // cout << comps;
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) 
            if(!vis[i][j]) {
                add_comps(i,j);
            }
        

    // for(int i = 1;i <= comps;i++) {
    //     sort(adj[i].begin(),adj[i].end());
    //     adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    //     cout << i << ": ";
    //     for(auto x:adj[i]) cout << x.fi << ' ';
    //     cout << '\n';
    // }

    dijkstra(dd);
    cout << dist[ comps_id[n][m] ];
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= m;j++) {
    //         cout << comps_id[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }



    return 0;
}