#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,h[MM],cur_h,a = 0,b = 0;
vector<int> adj[MM];

void load_graph()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par,int &x)
{
    for(auto v:adj[u]) {
        if(v != par) {
            h[v] = h[u] + 1;
            dfs(v,u,x);
        }
    }
    if(cur_h < h[u]) {
        x = u;
        cur_h = h[u];
    }
}

void solve()
{
    dfs(1,0,a);
    memset(h,0,sizeof(h));
    cur_h = 0;
    dfs(a,0,b);
    cout << cur_h;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}