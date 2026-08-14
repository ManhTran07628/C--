#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LG = 17;
int n,q,lg2[MM],a[MM];
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

int find_k_th(int k,int u)
{
    for(int j = LG;j >= 0;j--)
        if(k >> j & 1)
            u = up[u][j];
    return u;
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
    vector<pair<int,int>> edges;
    for(int i = 1;i < n;i++) {
        int u,v,x;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    dfs(1);
    process();
    cin >> q;
    while(q--) {
        int u,v,k; cin >> u >> v >> k;
        int edge = h[v] + h[u] - 2 * h[LCA(u,v)];
        int lck = LCA(u,v);
        if(k > edge) cout << -1 << '\n';
        else {
            int edge1 = h[u] - h[lck];
            if(k <= edge1) cout << find_k_th(k,u) << '\n';
            else if(k > edge1) {
                k -= edge1;
                int edge2 = h[v] - h[lck];
                cout << find_k_th(edge2 - k,v) << '\n';
            }
        }
    }
    return 0;
}