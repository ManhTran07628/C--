#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,a[MM],subtree[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    subtree[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        subtree[u] += subtree[v];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 2;i <= n;i++) {
        int u; cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << subtree[i] - 1 << ' ';
    return 0;
}