#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e7+7;
const int ML = 1e5+7;
const int LOG = 17;
int n,m,up[ML][LOG+1],h[ML],a[MM],x,y,z;
vector<int> adj[ML];

void load_graph()
{
    cin >> n >> m;
    for(int i = 1;i < n;i++) {
        int u,v = i;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> a[1] >> a[2];
    cin >> x >> y >> z;
}

void gen_query()
{
    for(int i = 3;i <= 2*m;i++) {
        a[i] = (1ll*x*a[i-2] + 1ll*y*a[i-1] + z)%n;
    }
}

void dfs(int u)
{
    for(auto v:adj[u]) {
        if(up[u][0] != v) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void process()
{
    dfs(0);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 0;i < n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int LCK(int u,int v)
{
    if(h[u] < h[v]) swap(u,v);

    for(int i = LOG;i >= 0;i--)
        if(h[up[u][i]] >= h[v])
            u = up[u][i];

    if(u == v) return u;

    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];

    return up[u][0];
}

void solve()
{
    gen_query();
    process();
    ll cnt = 0;
    ll lca = LCK(a[1],a[2]);
    int prev = lca;
    cnt += lca;
    for(int i = 2;i <= m;i++) {
        int u = (a[i*2-1]+prev)%n, v = a[i*2];
        lca = LCK(u,v);
        prev = lca;
        cnt += lca;
    }
    cout << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}