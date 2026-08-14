#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,x,y,vis[MM],ok = 0;
vector<int> adj[MM];

void dfs(int u,int d)
{
    for(auto v:adj[u]) {
        if(!vis[v]) {
            if(v == d) ok = 1;
            vis[v] = 1;
            dfs(v,d);
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
    }
    cin >> x >> y;
    dfs(x,y);
    if(ok) {
        cout << "yes";
        return 0;
    }
    memset(vis,0,sizeof(vis));
    dfs(y,x);
    if(ok) cout << "no";
    else cout << "unknown";
    return 0;
}