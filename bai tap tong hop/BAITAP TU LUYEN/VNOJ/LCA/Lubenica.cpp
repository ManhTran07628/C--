#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
ll n,h[MM],k,up[MM][LOG+1],Max[MM][LOG+1],Min[MM][LOG+1],lg2[MM];
vector<pair<ll,ll>> adj[MM];

void Lg2Arr()
{
    for(int i = 2;i < MM;i++)
        lg2[i] = lg2[i/2] + 1;
}

void dfs(ll u)
{
    for(auto x:adj[u]) {
        int v = x.fi,w = x.se;
        if(v != up[u][0]) {
            up[v][0] = u;
            Max[v][0] = w;
            Min[v][0] = w;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void process()
{
    Lg2Arr();
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            Max[i][j] = max(Max[i][j-1],Max[up[i][j-1]][j-1]);
            Min[i][j] = min(Min[i][j-1],Min[up[i][j-1]][j-1]);
        }
    }
}

ll lca(ll u,ll v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

void query(ll u,ll v)
{
    ll Lca = lca(u,v);
    ll dis1 = h[u] - h[Lca], dis2 = h[v] - h[Lca];
    ll maxlen = 0,minlen = oo;
    for(int i = LOG;i >= 0;i--) {
        if(dis1 >> i & 1) {
            maxlen = max(maxlen,Max[u][i]);
            minlen = min(minlen,Min[u][i]);
            u = up[u][i];
        }
    }

    for(int i = LOG;i >= 0;i--) {
        if(dis2 >> i & 1) {
            maxlen = max(maxlen,Max[v][i]);
            minlen = min(minlen,Min[v][i]);
            v = up[v][i];
        }
    }
    cout << minlen << ' ' << maxlen << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    process();
    cout << lca(1,3);
    return 0;
}