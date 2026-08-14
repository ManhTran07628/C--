#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int LOG = 18;
const int MM = 2e5+7;
int n,q,st[MM],en[MM],m = 0,up[MM][LOG+1],h[MM];
pair<int,int> a[MM];
struct edge{int u,v,w;} qr[MM];
vector<int> adj[MM];


void load_graph()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        cin >> qr[i].u >> qr[i].v >> qr[i].w;
        adj[qr[i].u].push_back(qr[i].v);
        adj[qr[i].v].push_back(qr[i].u);
    }
}

void dfs(int u,int par)
{
    st[u] = ++m;
    for(auto v:adj[u]) {
        if(v != par) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v,u);
        }
    }
    en[u] = ++m;
}

struct Segtree
{
    vector<int> st;
    Segtree(int n) : st(n*4+1){};

    void update(int id,int l,int r,int u,int v,int val)
    {
        if(l > v || r < u) return;
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,v,val);
        update(id*2+1,mid+1,r,u,v,val);
        st[id] = st[id*2] + st[id*2+1];
    }

    int get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }
};

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
    if(h[v] > h[u]) swap(u,v);
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

void solve()
{
    process();
    Segtree segt(m);
    for(int i = 1;i < n;i++) {
        int u = qr[i].u, v = qr[i].v;
        int child = up[v][0] == u ? v : u;
        segt.update(1,1,m,st[child],st[child],qr[i].w);
        segt.update(1,1,m,en[child],en[child],-qr[i].w);
    }
    cin >> q;
    while(q--) {
        int t,s;
        int x;
        cin >> t >> s >> x;
        if(t == 1) {
            int u = qr[s].u, v = qr[s].v;
            int child = up[v][0] == u ? v : u;
            segt.update(1,1,m,st[child],st[child],x);
            segt.update(1,1,m,en[child],en[child],-x);
        }
        else {
            int lca = LCK(s,x);
            int dist = segt.get(1,1,m,1,st[s]) + segt.get(1,1,m,1,st[x]);
            dist -= segt.get(1,1,m,1,st[lca])*2;
            cout << dist << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}