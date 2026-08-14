#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,a[MM];
ll h[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + a[v];
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        int u; cin >> u;
        if(u == 0) continue;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    h[1] = a[1];
    dfs(1,0);
    ll maxx = 0;
    for(int i = 1;i <= n;i++) maxx = max(maxx,h[i]);
    cout << maxx;
    return 0;
}