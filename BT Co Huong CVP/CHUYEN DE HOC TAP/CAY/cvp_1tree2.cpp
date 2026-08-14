#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LG = 17;
int n,q,lg2[MM],a[MM],f[MM];
int up[MM][LG+1],parent[MM],h[MM];
vector<int> adj[MM];
void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) {
        lg2[i] = lg2[i/2] + 1;
    }
}

// up[i][j] to tien thu 2^j cua thang i
void process()
{
    BuildLog2Arr();
    for(int j = 1;j <= LG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }   
    }
}

void dfs(int u)
{
    for(auto v : adj[u]) {
        if(v != up[u][0]) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

int LCA(int u,int v)
{
    if(h[u] < h[v]) return LCA(v,u);

    for(int i = LG;i >= 0;i--) 
        if(h[up[u][i]] >= h[v]) u = up[u][i];

    if(u == v) return u; // u la LCA cua u va v
    
    for(int i = LG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        f[ a[i] ] = i;
    }
    for(int i = 1;i < n;i++) {
        int u,v,x;
        cin >> u >> v >> x;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    process();
    up[0][0] = 1;
    cin >> q;
    while(q--) {
        int u,v;
        cin >> u >> v;
        cout << a[LCA(f[u],f[v])] << '\n';
    }
    return 0;
}