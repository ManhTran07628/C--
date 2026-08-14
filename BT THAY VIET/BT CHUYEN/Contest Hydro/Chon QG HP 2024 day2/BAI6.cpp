#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3e5+7;
ll n,m,X,Y,Q,a[MM],P[MM],b[MM];
vector<int> adj[MM];

void readinput()
{
    cin >> n >> m;
    cin >> X >> Y >> Q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= Q;i++) {
        cin >> P[i];
    }
}

struct Node{ll u,dist_u;};

struct cmp
{
    bool operator() (Node &a,Node &b){ return a.dist_u > b.dist_u;}
};


namespace subtask1
{
    ll dist[MM],vis[MM];
    bool checksub1()
    {
        return (Q == 1 && P[1] == X);
    }

    void dijkstra(int X)
    {
        for(int i = 1;i <= n;i++) dist[i] = oo;
        priority_queue<Node,vector<Node>,cmp> q;
        q.push({X,0});
        dist[X] = a[X];
        while(!q.empty()) {
            Node N = q.top(); q.pop();
            int u = N.u;
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto v:adj[u]) {
                if(dist[v] > dist[u] + a[v]) {
                    dist[v] = dist[u] + a[v];
                    q.push({v,dist[v]});
                }
            }
        }
    }

    void solve()
    {
        
        dijkstra(X);
        cout << dist[Y];
    }
}

namespace subtask3
{
    ll distX[MM],distY[MM],distP[MM],vis[MM];
    priority_queue<Node,vector<Node>,cmp> q;

    void dijkstra(ll dist[])
    {
        memset(vis,0,sizeof(vis));
        while(!q.empty()) {
            Node N = q.top(); q.pop();
            int u = N.u;
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto v:adj[u]) {
                if(dist[v] > dist[u] + a[v]) {
                    dist[v] = dist[u] + a[v];
                    q.push({v,dist[v]});
                }
            }
        }
    }

    void solve()
    {
        q.push({X,a[X]});
        for(int i = 1;i <= n;i++) distX[i] = oo;
        distX[X] = a[X];
        dijkstra(distX);

        q.push({Y,a[Y]});
        for(int i = 1;i <= n;i++) distY[i] = oo;
        distY[Y] = a[Y];
        dijkstra(distY);


        for(int i = 1;i <= n;i++) {
            q.push({i,distX[i]+distY[i]-a[i]});
            distP[i] = distX[i] + distY[i] - a[i];
        }
        dijkstra(distP);
        for(int i = 1;i <= Q;i++) {
            cout << distP[P[i]] << '\n';
        }
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    // subtask1::solve();
    subtask3::solve();
    return 0;
}