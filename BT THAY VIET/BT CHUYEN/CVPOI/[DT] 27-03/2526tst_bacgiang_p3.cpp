#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define des (ll) -1e18
#define pii pair<ll,ll>
const int MM = 1e6 + 7;
const int LOG = 19;
int n,q,h[MM],up[MM][LOG + 1],heavy[MM],head[MM],in[MM],m = 0;
int tour[MM],a[MM];
vector<pii> adj[MM];
struct Edge{int u,v,w;}; vector<Edge> edges;
int dfs(int u)
{
    int max_sz = 0,cur_sz = 1;
    for(auto N:adj[u]) {
        int v = N.fi, w = N.se;
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        int child_sz = dfs(v);
        cur_sz += child_sz;
        if(child_sz > max_sz) {
            heavy[u] = v;
            max_sz = child_sz;
        }
    }
    return cur_sz;
}

void decompose(int u,int H)
{
    in[u] = ++m; tour[m] = u; head[u] = H;
    if(heavy[u]) decompose(heavy[u],H);
    for(auto N:adj[u]) {
        int v = N.fi;
        if(v != heavy[u] && v != up[u][0]) 
            decompose(v,v); 
    }
}

ll st[MM * 4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[ tour[l] ];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

ll bit[MM * 4];

void update(int x)
{
    for(;x < MM;x += (x & -x)) bit[x]++;
}

int getbit(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

int querypath(int l,int r)
{
    return getbit(r) - getbit(l - 1);
}

void process()
{
    dfs(1);
    decompose(1,1);

    a[1] = oo;
    for(auto N:edges) {
        int u = N.u, v = N.v, w = N.w;
        if(up[u][0] == v) a[u] = w;
        else a[v] = w;
    }

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

    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) 
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

bool checkpath(int u,int v)
{
    int lca = LCK(u,v);
    ll cur = 0;
    while(head[lca] != head[u]) {
        cur += querypath(in[ head[u] ],in[u]);
        u = up[ head[u] ][0];
    }
    while(head[lca] != head[v]) {
        cur += querypath(in[ head[v] ],in[v]);
        v = up[ head[v] ][0];
    }
    if(in[u] < in[v]) cur += querypath(in[u],in[v]);
    else cur += querypath(in[v],in[u]);
    return cur;
}

ll Query(int u,int v)
{
    int lca = LCK(u,v);
    ll cur = oo;
    while(head[lca] != head[u]) {
        cur = min(cur,get(1,1,m,in[ head[u] ],in[u]));
        u = up[ head[u] ][0];
    }
    while(head[lca] != head[v]) {
        cur = min(cur,get(1,1,m,in[ head[v] ],in[v]));
        v = up[ head[v] ][0];
    }
    if(in[u] < in[v]) cur = min(cur,get(1,1,m,in[u] + 1,in[v]));
    else if(in[v] < in[u]) cur = min(cur,get(1,1,m,in[v] + 1,in[u]));
    return cur;
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
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    process();
    build(1,1,m);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u,v; cin >> u >> v;
            if(u == v) cout << 0 << '\n';
            else {
                if(checkpath(u,v) > 0) cout << -1 << '\n';
                else cout << Query(u,v) << '\n';
            }
        }
        else {
            int u; cin >> u;
            update(in[u]);
        }
    }

    return 0;
}