#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 2e5+7;
ll n,q,a[MM],st[MM],en[MM],Time = 0;
vector<int> adj[MM];
void dfs(int u,int par)
{
    st[u] = ++Time;
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
        }
    }
    en[u] = Time;
}


struct SegTree
{
    vector<ll> st;
    SegTree(int n) : st(n*4) {};

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = st[id*2] + st[id*2+1];
    }

    void update(int id,int l,int r,int u,ll val)
    {
        if(l > u || r < u) return;
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,val);
        update(id*2+1,mid+1,r,u,val);
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


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    SegTree g(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    g.build(1,1,n);
    while(q--) {
        int t,s,x;
        cin >> t >> s;
        if(t == 1) {
            cin >> x;
            g.update(1,st[1],en[n],st[s],x);
        }
        else cout << g.get(1,st[1],en[n],st[1],en[s]-1) << '\n';
    }
    return 0;
}