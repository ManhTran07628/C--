#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,par[MM],vis[MM];
vector<pair<int,int>> ar;
vector<int> adj[MM];
int find_sets(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_sets(par[a]);
}

void Union_sets(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return;
    par[b] = a;
    ar.push_back({a,b});
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(!vis[v]) {
            par[v] = u;
            dfs(v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) par[i] = i;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    dfs(1);
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            dfs(i);
            Union_sets(1,i);
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(auto i:ar) cout << i.fi << ' ' << i.se << '\n';
    return 0;
}