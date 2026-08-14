#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int LOG = 19;
int n,dif[MM],up[MM][LOG + 1],h[MM],f[MM];
vector<int> adj[MM];

void dfs(int u)
{
    for(auto v:adj[u]) {
        if(v == up[u][0]) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        dfs(v);
    }
}

int LCK(int u,int v)
{
    if(h[u] < h[v]) swap(u,v);
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v])
            u = up[u][i];
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

void upd(int u)
{
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        upd(v);
        dif[u] += dif[v];
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
    dfs(1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)   
            up[i][j] = up[ up[i][j-1] ][j-1];

    int q; cin >> q;
    while(q--) {
        int a,b; cin >> a >> b;
        int lca = LCK(a,b);
        dif[a]++;
        dif[b]++;
        dif[lca]--;
        dif[ up[lca][0] ]--;
        f[lca]++;
    }
    upd(1);
    int res = 0;
    for(int i = 2;i <= n;i++) {
        // cout << dif[i] << ' ' << f[i] << '\n';
        res += (dif[i] - f[i] == 0);
    }
    cout << res;
    return 0;
}