#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,par[MM],dis[MM],vis[MM];
vector<int> adj[MM];

void bfs()
{
    memset(dis,-1,sizeof(dis));
    dis[1] = 0;
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(!vis[v]) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                vis[v] = 1;
                q.push(v);
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
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    if(dis[n] == -1) cout << "IMPOSSIBLE";
    else {
        vector<int> path;
        int cur = n;
        path.push_back(n);
        while(par[cur] != 0) {
            path.push_back(par[cur]);
            cur = par[cur];
        }
        cout << path.size() << '\n';
        reverse(path.begin(),path.end());
        for(auto i:path) cout << i << ' ';
    }
    return 0;
}