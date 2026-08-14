#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,ds[MM],vis[MM],ok = 1;
vector<int> adj[MM];

void dfs(int u)
{
    for(auto v:adj[u]) {
        if(!ds[v]) {
            ds[v] = (ds[u] == 1 ? 2 : 1);
            dfs(v);
        }
        else {
            if(ds[v] == ds[u]) ok = 0;
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
    for(int i = 1;i <= n;i++) {
        if(!ds[i]) {
            ds[i] = 1;
            dfs(i);
        }
    }
    if(!ok) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i = 1;i <= n;i++) {
        cout << ds[i] << ' ';
    }
    return 0;
}