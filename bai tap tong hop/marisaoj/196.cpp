#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
int n,q,up[MM][LOG+1],h[MM],lg2[MM],sz[MM];
vector<int> adj[MM];

void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++)
        lg2[i] = lg2[i/2] + 1;
}

void dfs(int u)
{
    sz[u] = 1;
    for(auto v:adj[u]) {
        if(v != up[u][0]) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
            sz[u] += sz[v];
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

int lca(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) 
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];

    if(u == v) return u;

    for(int i = LOG;i >= 0;i--) 
        if(up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    return up[u][0];
}

int kth_anc(int u,int k)
{
    for(int i = LOG;i >= 0;i--)
        if(k >> i & 1)
            u = up[u][i];
    return u;
}

void query(int u,int v)
{
    int Lca = lca(u,v);
    int dis = h[u] + h[v] - 2*h[Lca];
    if(dis % 2) cout << 0;
    else {
        if(h[u] > h[v]) swap(u,v);

        int v_r = kth_anc(v,dis/2-1);
        int mid = up[v_r][0];

        if(h[u] == h[v]) {
            int u_r = kth_anc(u,dis/2-1);
            cout << sz[1] - sz[v_r] - sz[u_r];
        }
        else cout << sz[mid] - sz[v_r];
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    process();
    while(q--) {
        int u,v;
        cin >> u >> v;
        query(u,v);
    }
    return 0;
}