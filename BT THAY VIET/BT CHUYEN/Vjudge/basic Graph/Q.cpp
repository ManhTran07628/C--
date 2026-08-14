#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,vis[MM],cnt = 0;
vector<vector<int>> adj;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}