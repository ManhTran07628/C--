#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
const int LOG = 18;
int n,q,st[MM],en[MM],m = 0;
vector<int> adj[MM];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    st[u] = ++m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    en[u] = m;
}

struct SegTree
{
    vector<ll> st,lazy;
    SegTree(int n) : st(n*4+1), lazy(n*4+1) {};

    void fix(int id,int l,int r)
    {
        if(!lazy[id]) return;
        st[id] += lazy[id] * (r-l+1);
        if(l != r) {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }

    void update(int id,int l,int r,int u,int v,ll val) {
        fix(id,l,r);
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            lazy[id] += val;
            fix(id,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,v,val);
        update(id*2+1,mid+1,r,u,v,val);
        st[id] = st[id*2] + st[id*2+1];
    }

    ll get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }

};

int h[MM],up[MM][LOG+1];
struct LCA
{

    void dfs_lca(int u,int par)
    {
        for(auto v:adj[u]) {
            if(v == par) continue;
            if(up[u][0] != v) {
                up[v][0] = u;
                h[v] = h[u] + 1;
                dfs_lca(v,u);
            }
        }
    }


    void process()
    {
        dfs_lca(1,0);
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
        for(int i = LOG;i >= 0;i--)
            if(h[ up[u][i] ] >= h[v])
                u = up[u][i];

        if(u == v) return u;

        for(int i = LOG;i >= 0;i--)
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        return up[u][0];
    }
};


void solve()
{
    dfs(1,0);
    // for(int i = 1;i <= n;i++) cout << st[i] << ' ' << en[i] << '\n';
    SegTree ST(n+7);
    LCA L;

    L.process();
    while(q--) {
        ll t,u,v;
        cin >> t >> u >> v;
        if(t == 1) ST.update(1,1,n,st[u],en[u],v);
        else if(t == 2) ST.update(1,1,n,st[u],st[u],v);
        else {
            int lca = L.LCK(u,v);
            ll sum = ST.get(1,1,n,1,st[u]) + ST.get(1,1,n,1,st[v]) - ST.get(1,1,n,1,st[lca]);
            cout << ST.get(1,1,n,1,st[u]) << ' ' << ST.get(1,1,n,1,st[v]) << ' ' << 
            ST.get(1,1,n,1,st[lca]) << '\n';
            // cout << sum << '\n';
        }
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
    readinput();
    solve();
    return 0;
}