#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,q;
vector<int> adj[MM];
struct DSU{
    vector<int> par,h,color;
    DSU(int n) : par(n), h(n), color(n) {};
    void dfs(int u)
    {
        for(auto v:adj[u]) {
            if(v != par[u]) {
                par[v] = u;
                h[v] = h[u] + 1;
                dfs(v);
            }
        }
    }

    void bin_lifting(int u,int v,int x) 
    {
        vector<int> vt;
        while(h[u] < h[v]) {
            if(!color[v]) color[v] = x;
            vt.push_back(v);
            v = par[v];
        }
        if(!color[u]) color[u] = x;
        for(auto e:vt) 
            par[e] = par[u];
    }

};


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
    DSU g(n+7);
    g.dfs(1);
    while(q--) {
        int x,y,z;
        cin >> x >> y >> z;
        g.bin_lifting(x,y,z);
    }
    for(int i = 1;i <= n;i++) {
        cout << g.color[i] << ' ';
    }
    return 0;
}