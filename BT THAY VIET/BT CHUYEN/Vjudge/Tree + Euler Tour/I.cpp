#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 18;
int n,q,up[MM][LOG+1],h[MM],u_st,v_st,u_jump,v_jump,u_add,v_add;
int cur_u,cur_v;
vector<int> adj[MM];

void ReadInput()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> u_st >> v_st >> u_jump >> v_jump >> u_add >> v_add;
}

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(up[u][0] != v) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v,u);
        }
    }
}

void process()
{
    dfs(1,0);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int LCK(int u,int v)
{
    if(h[u] < h[v]) swap(u,v);

    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }
    if(u == v) return u;
    
    for(int i = LOG;i >= 0;i--) 
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    
    return up[u][0];
}

void solve()
{
    process();
    cur_u = u_st;
    cur_v = v_st;
    ll ans = LCK(cur_u,cur_v);
    for(int i = 2;i <= q;i++) {
        int new_u = (1ll * cur_u * u_jump + u_add) % n + 1;
        int new_v = (1ll * cur_v * v_jump + v_add) % n + 1;
        ll lca = LCK(new_u,new_v);
        ans ^= lca;
        cur_u = new_u;
        cur_v = new_v;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ReadInput();
    solve();
    return 0;
}