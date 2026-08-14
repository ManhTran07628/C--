#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int vis[MM],n;
int h[MM],cur_h = 0;
vector<int> adj[MM];
void dfs_a(int u,int &x)
{
    vis[u] = 1;
    if(h[u] > cur_h) {
        x = u;
        cur_h = h[u];
    }
    for(auto v:adj[u]) {
        if(!vis[v]) {
            h[v] = h[u] + 1;
            dfs_a(v,x);
        }
    }
}

int a = 1,b = 1;
int find_diameter()
{
    dfs_a(1,a);
    memset(vis,0,sizeof(vis));
    memset(h,0,sizeof(h));
    cur_h = 0;
    dfs_a(a,b);
    return cur_h;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_diameter();
    cout << a << ' ' << b;
    return 0;
}