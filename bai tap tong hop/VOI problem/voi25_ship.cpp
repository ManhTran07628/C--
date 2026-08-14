#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
const int LOG = 17;
ll n,k,w[MM],up[MM][LOG+1],st[MM][LOG+1],lg2[MM],h[MM];
ll dp[MM];
vector<ll> adj[MM];

void Log2Arr()
{
    for(int i = 2;i < MM;i++) 
        lg2[i] = lg2[i/2] + 1;
}

void dfs(ll u)
{
    for(auto v:adj[u]) {
        if(v != up[u][0]) {
            up[v][0] = u;
            st[v][0] = max(w[v],w[u]);
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void process()
{
    Log2Arr();
    dfs(1);
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            st[i][j] = max(st[i][j-1],st[up[i][j-1]][j-1]);
        }
    }
}

ll lca(ll u,ll v) 
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(h[up[u][i]] >= h[v]) 
            u = up[u][i];
    }

    if(u == v) return v;

    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

ll MaxQuery(ll u,ll v)
{
    ll k = lca(u,v);
    ll d_u = h[u] - h[k];
    ll d_v = h[v] - h[k];
    ll max_dist = 0;

    for(int i = LOG;i >= 0;i--) {
        if(d_u >> i & 1) {
            max_dist = max(max_dist,st[u][i]);
            u = up[u][i];
        }
    }

    for(int i = LOG;i >= 0;i--) {
        if(d_v >> i & 1) {
            max_dist = max(max_dist,st[v][i]);
            v = up[v][i];
        }
    }
    return max_dist;
}

// dp[i] gia tri lon nhat khi dang o dinh i
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "SHIP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> w[i];

    for(int i = 1;i < n;i++) {
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    process();
    cin >> k;
    for(int i = 1;i <= k;i++) {
        ll u,v;
        cin >> u >> v;
        if(dp[u] == 0 && u != 1) continue;
        dp[v] = max(dp[v],dp[u]+MaxQuery(u,v));
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}