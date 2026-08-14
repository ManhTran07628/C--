#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,vis1[MM],vis2[MM];
vector<vector<int>> adj,rev;

void dfs(int u,int vis[],vector<vector<int>> &adj)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(!vis[v]) {
            dfs(v,vis,adj);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1); rev.resize(n+1);
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    dfs(1,vis1,adj);
    for(int i = 1;i <= n;i++) {
        if(!vis1[i]) {
            cout << "NO" << '\n';
            cout << 1 << ' ' << i;
            return 0;
        }
    }
    dfs(1,vis2,rev);
    for(int i = 1;i <= n;i++) {
        if(!vis2[i]) {
            cout << "NO" << '\n';
            cout << i << ' ' << 1;
            return 0;
        }
    }
    cout << "YES";
    return 0;
}