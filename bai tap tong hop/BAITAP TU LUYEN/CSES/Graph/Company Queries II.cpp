#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
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
        if(!h[v]) {
            dfs(v);
            h[u] = h[v] + 1;
        }
    }
}

int LCA(int u,int v)
{
    if(h[u] != h[v]) {
        if(h[u] < h[v]) swap(u,v);
        int k = h[u] - h[v];
        for(int j = 0;(1 << j) <= k;j++) {
            if((k >> j) & 1) 
                u = up[u][j];
        }
    }
    if(u == v) return u; // u la LCA cua u va v
    int k = lg2[h[u]];
    for(int j = k;j >= 0;j--) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 2;i <= n;i++) {
        int b;
        cin >> b;
        up[i][0] = b;
    }
    up[1][0] = 1;
    dfs(1);
    while(q--) {
        int u,v;
        cin >> u >> v;
        cout << LCA(u,v) << '\n';
    }
    return 0;
}