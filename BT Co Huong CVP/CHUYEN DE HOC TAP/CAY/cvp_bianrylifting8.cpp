#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 4e5 + 7;
const int LOG = 18;
ll n,L,h[MM],up[MM][LOG + 1],m = 0;
ll sum[MM][LOG + 1];
vector<pii> adj[MM];

void dfs(int u)
{
    for(auto U:adj[u]) {
        ll v = U.fi, w = U.se;
        if(up[u][0] == v) continue;
        up[v][0] = u;
        sum[v][0] = w;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

ll st[MM * 4];

void process()
{
    dfs(1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
            sum[i][j] = sum[i][j-1] + sum[ up[i][j-1] ][j-1];
        }
}

pii bin_lift(int u,int k)
{
    ll cnt = 0;
    for(int j = LOG;j >= 0;j--)
        if(k >> j & 1) {
            cnt += sum[u][j];
            u = up[u][j];
        }
    return {u,cnt};
}

int find_anc_node(int u)
{
    int l = 1, r = h[u], res = u;
    while(l <= r) {
        int mid = (l + r) / 2;
        pii cur = bin_lift(u,mid);
        if(cur.se <= L) {
            res = cur.fi;
            l = mid + 1;
        }
        else r = mid - 1;
        // cout << mid << ' ' << bin_lift(u,mid) << ' ' << L << '\n'; 
    }
    return res;
}

int LCK(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int j = LOG;j >= 0;j--)
        if(h[ up[u][j] ] >= h[v]) u = up[u][j];
    if(u == v) return u;
    for(int j = LOG;j >= 0;j--)
        if(up[u][j] != up[v][j]) 
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

void query(int u,int v)
{
    int lca = LCK(u,v);
    st[u]++;
    st[v]++;
    st[lca]--;
    if(lca != 1) st[ up[lca][0] ]--;
}

void ddfs(int u)
{
    for(auto N:adj[u]) {
        int v = N.fi;
        if(up[u][0] == v) continue;
        ddfs(v);
        st[u] += st[v];
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> L;
    for(int i = 2;i <= n;i++) {
        int u; ll w; cin >> u >> w;
        adj[u].push_back({i,w});
        adj[i].push_back({u,w});
    }
    process();
    for(int u = 1;u <= n;u++) {
        int v = find_anc_node(u);
        query(u,v);
    }
    ddfs(1);
    for(int i = 1;i <= n;i++) {
        cout << st[i] << '\n';
    }
    // for(int i = 1;i <= n;i++) cout << i << ' ' << find_anc_node(i) << '\n';
    // cout << find_anc_node(2);

    // cout << h[3];
    // cout << bin_lift(3,2);
    // for(int i = 1;i <= n;i++) cout << i << ' ' << sum[i][0] << '\n';
    return 0;
}
