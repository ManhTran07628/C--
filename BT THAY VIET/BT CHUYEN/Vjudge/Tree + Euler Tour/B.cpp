#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,cNode[MM];
vector<int> adj[MM];

void load_graph()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v = i+1;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    cNode[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        cNode[u] += cNode[v];
    }
}

void solve()
{
    dfs(1,0);
    for(int i = 1;i <= n;i++) {
        cout << cNode[i]-1 << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}