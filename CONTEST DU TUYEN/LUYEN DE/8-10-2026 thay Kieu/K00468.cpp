#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int LOG = 19;
int n,q,a[MM];
vector<int> adj[MM];

int up[MM][LOG + 1],h[MM],head[MM],heavy[MM],num[MM],tour[MM],m = 0;

int dfs(int u)
{
    int max_sz = 0, cur_sz = 1;
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
    num[u] = ++m; tour[m] = u;
    head[u] = H;
    if(heavy[u])
        decompose(heavy[u],H);
    
    for(auto v:adj[u]) {
        if(v != heavy[u] && up[u][0] != v) 
            decompose(v,v);
    }
}

struct Node
{
    ll sum,prefix,suffix,Max;
} st[MM * 4];

Node Merge(Node a,Node b)
{
    ll sum = a.sum + b.sum;
    ll prefix = max(a.prefix,a.sum + b.prefix);
    ll suffix = max(b.suffix,a.suffix + b.sum);
    ll Max = max({a.suffix + b.prefix,a.Max,b.Max});
    return {sum,prefix,suffix,Max};
}

void build(int id,int l,int r)
{
    if(l == r) {
        ll val = a[ tour[l] ];
        st[id] = {val,val,val,val};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,ll val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {val,val,val,val};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {0,-oo,-oo,-oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

void process()
{
    dfs(1);
    decompose(1,1);
    build(1,1,n);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
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

void update_node(int u,ll x)
{
    update(1,1,n,num[u],x);
}

Node query(int u,int v)
{
    int lca = LCK(u,v);
    Node v1 = {0,-oo,-oo,-oo}, v2 = {0,-oo,-oo,-oo};

    // cout << head[lca] << ' ' << head[u] << '\n';

    while(head[lca] != head[u]) {
        Node chain = get(1,1,n,num[ head[u] ],num[u]);
        v1 = Merge(chain,v1);
        u = up[ head[u] ][0];
    }

    while(head[lca] != head[v]) {
        Node chain = get(1,1,n,num[ head[v] ],num[v]);
        v2 = Merge(chain,v2);
        v = up[ head[v] ][0];
    }

    Node mid;
    if(num[u] < num[v]) {
        mid = get(1,1,n,num[u],num[v]);
    }
    else {
        mid = get(1,1,n,num[v],num[u]);
        swap(mid.prefix,mid.suffix);
    }
    swap(v1.prefix,v1.suffix);
    v1 = Merge(Merge(v1,mid),v2);
    return v1;
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    process();
    while(q--) {
        char type; cin >> type;
        if(type == 'U') {
            int u,x; cin >> u >> x;
            update_node(u,x);
        }
        else {
            int u,v; cin >> u >> v;
            Node res = query(u,v);
            cout << res.Max << '\n';
        }
    }
    return 0;
}