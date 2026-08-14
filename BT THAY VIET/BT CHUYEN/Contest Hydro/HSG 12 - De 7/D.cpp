#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,m,comp[MM],comp_sz[MM],vis[MM],diaA[MM],h[MM];
vector<int> adj[MM];

void init()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


int cur_length = 0;

void dfs(int u,int &NodeA)
{
    vis[u] = 1;
    if(h[u] > cur_length) {
        NodeA = u;
        cur_length = h[u];
    }
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        h[v] = h[u] + 1;
        dfs(v,NodeA);
    }   
}

void solve()
{
    int id = 0;
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            dfs(i,diaA[ i ]);
            cur_length = 0;
        }
    }
    memset(vis,0,sizeof(vis));
    memset(h,0,sizeof(h));
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            h[ diaA[i] ] = 1;
            dfs(diaA[ i ],id);
            ans += cur_length;
            cur_length = 0;
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}