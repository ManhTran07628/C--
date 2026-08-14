#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,q,a[MM],st[MM],en[MM],m = 0;
vector<int> adj[MM];


void load_graph()
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
    st[u] = ++m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    en[u] = ++m;
}

struct Segtree
{
    vector<ll> st;
    Segtree(int n) : st(n*4+1){};

    void update(int id,int l,int r,int u,int v,ll val)
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

    ll get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }
};



void solve()
{
    Segtree segt(m);
    for(int i = 1;i <= n;i++) {
        segt.update(1,1,m,st[i],st[i],a[i]);
        segt.update(1,1,m,en[i],en[i],-a[i]);
    }
    while(q--) {
        int t,s;
        ll x;
        cin >> t >> s;
        if(t == 1) {
            cin >> x;
            segt.update(1,1,m,st[s],st[s],x);
            segt.update(1,1,m,en[s],en[s],-x);
        }
        else {
            cout << segt.get(1,1,m,1,st[s]) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    dfs(1,0);
    // for(int i = 1;i <= n;i++) cout << st[i] << ' ' << en[i] << '\n';
    solve();
    return 0;
}