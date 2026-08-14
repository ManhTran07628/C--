#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 18;
int n,q,e[MM],st[MM],en[MM],m = 0,up[MM][LOG+1],h[MM];
vector<int> adj[MM];
void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> e[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs_path(int u,int par)
{
    st[u] = ++m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs_path(v,u);
    }
    en[u] = ++m;
}

struct SegTree
{
    vector<ll> st;
    SegTree(int n) : st(n*4+1) {};

    void update(int id,int l,int r,int pos,ll val)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        st[id] = st[id*2] ^ st[id*2+1];
    }

    ll get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) ^ get(id*2+1,mid+1,r,u,v);
    }
};


void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(up[u][0] != v) {
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v,u);
        }
    }
}

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

void solve()
{
    dfs_path(1,0);
    process();
    SegTree St(m);
    for(int i = 1;i <= n;i++) {
        St.update(1,1,m,st[i],e[i]);
        // St.update(1,1,m,en[i],-e[i]);
    }

    while(q--) {
        ll t,x,y;
        cin >> t >> x >> y;
        if(t == 1) {
            St.update(1,1,m,st[x],y);
            // St.update(1,1,m,en[x],-y);
        }
        else {
            int lca = LCK(x,y);
            ll dist = St.get(1,1,m,1,st[x]) ^ St.get(1,1,m,1,st[y]) ^ e[lca];
            cout << dist << '\n';
        }
    }
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}