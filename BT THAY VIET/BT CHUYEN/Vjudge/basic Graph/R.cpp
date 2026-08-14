#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,vis[MM],par[MM],a,b;
vector<vector<int>> adj;

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(!vis[v]) {
                par[v] = u;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    adj.resize(n+1);
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(a);
    if(!vis[b]) cout << -1;
    else {
        vector<int> path;
        while(b != a) {
            path.push_back(b);
            b = par[b];
        }
        path.push_back(a);
        reverse(path.begin(),path.end());
        cout << path.size()-1 << '\n';
        for(auto x:path) cout << x << ' ';
    }
    return 0;
}