#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,c,h[MM];
set<int> adj[MM];

void dfs(int u,int par)
{
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
    cin >> n >> c;
    for(int i = 1;i <= n;i++) {
        int e,b1,b2; cin >> e >> b1 >> b2;
        adj[e].insert(b1);
        adj[b1].insert(e);
        adj[e].insert(b2);
        adj[b2].insert(e);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << h[i] + 1 << '\n';
    return 0;
}