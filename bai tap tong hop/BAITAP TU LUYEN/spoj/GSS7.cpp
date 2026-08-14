#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
const int MM = 1e5+7;
const int LOG = 17;
int n,q,h[MM],head[MM],heavy[MM],up[MM][LOG+1],num[MM],m = 0;
int tour[MM];
ll a[MM];
vector<int> adj[MM];

void readinput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
}

int dfs(int u)
{
    int cur_sz = 1,max_sz = 0;
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        int child_sz = dfs(v);
        cur_sz += child_sz;
        if(child_sz > max_sz) {
            max_sz = child_sz;
            heavy[u] = v;
        }
    }
    return cur_sz;
}

void decompose(int u,int H)
{
    tour[++m] = u;
    num[u] = m; head[u] = H;
    if(heavy[u]) decompose(heavy[u],H);
    
    for(auto v:adj[u]) {
        if(up[u][0] != v && v != heavy[u]) 
            decompose(v,v);
    }
}

struct Node{ll sum,pfmax,sfmax,max;} st[MM*4];

ll lazy[MM*4];

Node merge(Node X,Node Y) 
{
    ll cur_sum = X.sum + Y.sum;
    ll pfmax = max(X.pfmax,X.sum + Y.pfmax);
    ll sfmax = max(Y.sfmax,X.sfmax + Y.sum);
    ll maxsum = max({X.max,Y.max,X.sfmax + Y.pfmax});
    return {cur_sum,pfmax,sfmax,maxsum};
}

void build(int id,int l,int r)
{
    lazy[id] = oo;
    if(l == r) {
        ll cur = a[ tour[l] ];
        st[id] = {cur,max(0ll,cur),max(0ll,cur),max(0ll,cur)};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = merge(st[id*2],st[id*2+1]);
}

void fix(int id,int l,int r)
{
    if(lazy[id] == oo) return;
    ll sum = (r-l+1) * lazy[id];
    ll best = (lazy[id] > 0 ? sum : lazy[id]);
    st[id] = {sum,max(0ll,best),max(0ll,best),max(0ll,best)};
    
    if(l != r) {
        lazy[id*2] = lazy[id];
        lazy[id*2+1] = lazy[id];
    }
    lazy[id] = oo;
}

void update(int id,int l,int r,int u,int v,ll val) {
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] = val;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {0,0,0,0};
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

int LCA(int u,int v)
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

void qr_update(int u,int v,ll val)
{
    int lca = LCA(u,v);
    while(head[u] != head[lca]) {
        update(1,1,n,num[ head[u] ],num[u],val);
        u = up[ head[u] ][0];
    }

    while(head[v] != head[lca]) {
        update(1,1,n,num[ head[v] ],num[v],val);
        v = up[ head[v] ][0];
    }
    
    if(num[v] < num[u]) swap(u,v);
    update(1,1,n,num[u],num[v],val);
}

Node reverseNode(Node x) {
    return {x.sum,x.sfmax,x.pfmax,x.max};
}

ll query(int u,int v)
{
    int lca = LCA(u,v);
    Node Node_u = {0,0,0,0}, Node_v = {0,0,0,0};
    while(head[u] != head[lca]) {
        auto cur = get(1,1,n,num[ head[u] ],num[u]);
        Node_u = merge(cur,Node_u);
        u = up[ head[u] ][0];
    }
    
    while(head[v] != head[lca]) {
        auto cur = get(1,1,n,num[ head[v] ],num[v]);
        Node_v = merge(cur,Node_v);
        v = up[ head[v] ][0];
    }
    Node middle_path = {0,0,0,0};
    if(num[u] < num[v]) {
        middle_path = get(1,1,n,num[u],num[v]);
    }
    else {
        middle_path = get(1,1,n,num[v],num[u]);
        middle_path = reverseNode(middle_path);
    }
    Node_u = reverseNode(Node_u);
    Node_u = merge(merge(Node_u,middle_path),Node_v);
    return Node_u.max;
}

void solve()
{
    dfs(1);
    decompose(1,1);
    build(1,1,n);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++) 
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
    
    while(q--) {
        ll t,A,B,C;
        cin >> t >> A >> B;
        if(t == 1) cout << query(A,B) << '\n';
        else {
            cin >> C;
            qr_update(A,B,C);
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