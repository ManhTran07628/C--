#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,st[MM],q,par[MM];
vector<int> adj[MM];

void dfs(int u)
{
    cout << u << ' ';
    for(auto v:adj[u]) {
        if(v == par[u]) continue;
        par[v] = u;
        dfs(v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    // while(q--) {
    //     vector<int> res;
    //     int x; cin >> x;
    //     dfs1(x,res);
    //     for(auto x:res) cout << x << ' '; cout << '\n';
    // }
    return 0;
}