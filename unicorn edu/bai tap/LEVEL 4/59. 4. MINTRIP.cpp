#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,h[MM];
ll ans[MM];
vector<int> adj[MM],land[MM];


void dfs(int u,int par)
{
    for(int i = u;i <= n;i += u) land[u].push_back(i);
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }

    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) {
        for(auto u:land[i]) {
            ans[i] += h[u] * 2;
        }
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << '\n';

    return 0;
}