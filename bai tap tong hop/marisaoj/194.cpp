#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
ll n,q,up[MM][LOG+1],h[MM],diff[MM];
vector<int> adj[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs_sz(int u)
{
    for(auto v:adj[u]) {
        if(up[u][0] != v) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs_sz(v);
        }
    }
}

void process()
{
    dfs_sz(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int LCK(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) 
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
            diff[u] += diff[v];
        }
    }
}


void solve()
{
    process();
    while(q--) {
        ll u,v,w;
        cin >> u >> v >> w;
        if(h[v] < h[u]) swap(u,v);
        int res = LCK(u,v);
        if(res == 0) res = 1;
        diff[u] += w;
        diff[v] += w;
        diff[res] -= w;
        if(res != 1) diff[up[res][0]] -= w;
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << diff[i] << ' ';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}