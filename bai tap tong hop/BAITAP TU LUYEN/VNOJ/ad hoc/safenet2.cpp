#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e4+7;
ll n,m,low[MM],num[MM],cNode[MM],timeDFS = 0,ans = 0;
vector<ll> adj[MM];

void dfs(ll u,ll par)
{
    low[u] = num[u] = ++timeDFS;
    cNode[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!num[v]) {
            dfs(v,u);
            cNode[u] += cNode[v];
            low[u] = min(low[v],low[u]);
            if(low[v] == num[v]) {
                ll A = cNode[v];
                ll B = n-A;
                // cout << v << ' ' << cNode[v] << '\n';
                ans += A*B;
            }
        }
        else {
            low[u] = min(low[u],num[v]);
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
    dfs(1,1);
    cout << ans;
    return 0;
}