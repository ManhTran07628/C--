#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
const int LOG = 19;
ll n,a[MM],weight[MM];
int up[MM][LOG + 1],h[MM],diff[MM];
vector<pii> adj[MM];

void dfs(int u)
{
    for(auto N:adj[u]) {
        int v = N.fi, w = N.se;
        if(up[u][0] == v) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        weight[v] = weight[u] + w;
        dfs(v);
    }
}

int bin_lifting(int u,int d)
{
    for(int i = LOG;i >= 0;i--)
        if(d >> i & 1)
            u = up[u][i];
    return u;
}

void bins(int cur_node)
{
    int L = 0, R = h[cur_node], res = cur_node;
    while(L <= R) {
        int mid = (L + R) / 2;
        int anc_node = bin_lifting(cur_node,mid);
        ll d = weight[cur_node] - weight[anc_node];
        if(d <= a[cur_node]) {
            res = anc_node;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    // cout << cur_node << ' ' << res << '\n';
    if(cur_node != res) {
        diff[ up[cur_node][0] ]++;
        diff[ (res == 1 ? 0 : up[res][0]) ]--;
    }
}


void dfs2(int u)
{
    bins(u);
    for(auto N:adj[u]) {
        int v = N.fi;
        if(up[u][0] == v) continue;
        dfs2(v);
    }
}

void dfs3(int u)
{
    for(auto N:adj[u]) {
        int v = N.fi;
        if(up[u][0] == v) continue;
        dfs3(v);
        diff[u] += diff[v];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
    dfs2(1);
    dfs3(1);
    for(int i = 1;i <= n;i++) cout << diff[i] << ' ';
    return 0;
}
