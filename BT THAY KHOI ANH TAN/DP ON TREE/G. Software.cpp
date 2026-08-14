#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int LOG = 17;
int n,q,a[MM],up[MM][LOG + 1];
int h[MM],d[MM];
vector<int> adj[MM];
void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        up[v][0] = u;
        dfs(v,u);
    }
}


void dfs_2(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs_2(v,u);
        d[u] += d[v];
    }
}

void solve()
{
    dfs(1,0);
    while(q--) {
        int x;
        cin >> x;
        d[1]--;
        d[ up[x][0] ]++;
    }
    dfs_2(1,0);
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        cnt += (a[i] + d[i]) % 2;
    }
    cout << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}