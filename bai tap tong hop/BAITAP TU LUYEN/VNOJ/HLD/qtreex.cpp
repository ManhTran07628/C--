#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e9
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e4+7;
const int LOG = 15;
int t,n,m = 0,tour[MM];
int up[MM][LOG + 1],num[MM],head[MM],heavy[MM],vals[MM],h[MM];
int pos_edge[MM];
vector<int> adj[MM];
struct Edge{int u,v,w;} edges[MM];

struct Node
{
    int min_w,max_w;
} st[MM * 4];

int lazy[MM * 4];

void init()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u,v,w};
    }
}

void reset_all() {
    m = 0;
    for(int i = 1;i <= n;i++) {
        adj[i].clear();
        heavy[i] = 0;
        vals[i] = 0;
        h[i] = 0;
        num[i] = 0;
        tour[i] = 0;
        for(int j = 0;j <= LOG;j++) up[i][j] = 0;
    }
    for (int i = 0;i < MM*4;i++) {
        st[i].min_w = oo;
        st[i].max_w = -oo;
        lazy[i] = 0;
    }
}

int dfs(int u)
{
    int max_sz = 0,cur_sz = 1;
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;

        h[v] = h[u] + 1;
        up[v][0] = u;
        int child_sz = dfs(v);
        cur_sz += child_sz;

        if(max_sz < child_sz) {
            heavy[u] = v;
            max_sz = child_sz;
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
        if(v != heavy[u] && up[u][0] != v) 
            decompose(v,v);
    }
}

void process()
{
    dfs(1);
    decompose(1,1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];

    for(int i = 1;i < n;i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if(up[u][0] == v) {
            vals[u] = w;
            pos_edge[i] = u;
        }
        else {
            vals[v] = w;
            pos_edge[i] = v;
        }
    }

}

Node Merge(Node a,Node b)
{
    int min_w = min(a.min_w,b.min_w);
    int max_w = max(a.max_w,b.max_w);
    return {min_w,max_w};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id].max_w = st[id].min_w = vals[ tour[l] ];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void fix(int id,int l,int r)
{
    lazy[id] %= 2;
    if(!lazy[id]) return;
    swap(st[id].min_w, st[id].max_w);
    st[id].min_w = -st[id].min_w;
    st[id].max_w = -st[id].max_w;


    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int pos,int vals)
{
    fix(id,l,r);
    if(l > pos || r < pos) return;
    if(l == r) {
        fix(id,l,r);
        st[id].max_w = st[id].min_w = vals;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,vals);
    update(id*2+1,mid+1,r,pos,vals);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void Negate(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id]++;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    Negate(id*2,l,mid,u,v);
    Negate(id*2+1,mid+1,r,u,v);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {oo,-oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

int LCA(int u,int v)
{
    if(h[u] < h[v]) swap(u,v);
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v])
            u = up[u][i];

    if(u == v) return u;

    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

void Negate_Query(int u,int v)
{
    int lca = LCA(u,v);
    while(head[u] != head[lca]) {
        Negate(1,1,n,num[ head[u] ],num[u]);
        u = up[ head[u] ][0];
    }   
    if(u != lca) Negate(1,1,n,num[lca]+1,num[u]);
    while(head[v] != head[lca]) {
        Negate(1,1,n,num[ head[v] ],num[v]);
        v = up[ head[v] ][0];
    }
    if(v != lca) Negate(1,1,n,num[lca]+1,num[v]);
}   

void Change_Query(int u,int vals)
{
    update(1,1,n,num[ pos_edge[u] ],vals);
}

int Get_Query(int u,int v)
{
    Node qr = {oo, -oo};
    int lca = LCA(u,v);
    while(head[u] != head[lca]) {
        auto x = get(1,1,n,num[ head[u] ],num[u]);
        qr = Merge(qr,x);
        u = up[ head[u] ][0];
    }   
    if(u != lca) {
        auto x = get(1,1,n,num[lca]+1, num[u]);
        qr = Merge(qr, x);
    }
    while(head[v] != head[lca]) {
        auto x = get(1,1,n,num[ head[v] ],num[v]);
        qr = Merge(qr,x);
        v = up[ head[v] ][0];
    }
    if(v != lca) {
        auto x = get(1,1,n,num[lca]+1, num[v]);
        qr = Merge(qr, x);
    }
    return qr.max_w;
}


void solve()
{
    init();
    process();
    build(1,1,n);
    string type;
    while(cin >> type) {
        if(type == "DONE") break;
        int u,v;
        cin >> u >> v;
        if(type == "CHANGE") Change_Query(u,v);
        if(type == "NEGATE") Negate_Query(u,v);
        if(type == "QUERY") {
            if(u == v) cout << 0 << '\n';
            else cout << Get_Query(u,v) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        reset_all();
        solve();
    }
    return 0;
}