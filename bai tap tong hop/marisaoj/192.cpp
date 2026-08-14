#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
ll n,q,up[MM][LOG+1],Lg2[MM],high[MM],weight[MM];
vector<pair<ll,ll>> adj[MM];

void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) 
        Lg2[i] = Lg2[i/2] + 1;
}

void dfs(ll u)
{
    for(auto [v,w]:adj[u]) {
        if(v != up[u][0]) {
            up[v][0] = u;
            high[v] = high[u] + 1;
            weight[v] += weight[u] + w;
            dfs(v);
        }
    }
}

void process()
{
    BuildLog2Arr();
    dfs(1);

    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

ll lca(ll u,ll v)
{
    if(high[v] > high[u])
        return lca(v,u);

    for(int i = LOG;i >= 0;i--) { // can bang do sau
        if(high[up[u][i]] >= high[v]) 
            u = up[u][i];
    }
    if(u == v) return u;
    // tim lca
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

ll getQuery(ll u,ll v)
{
    ll Lca = lca(u,v);
    return weight[u] + weight[v] - 2*weight[Lca];
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    process();
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << getQuery(l,r) << '\n';
    }
    return 0;
}