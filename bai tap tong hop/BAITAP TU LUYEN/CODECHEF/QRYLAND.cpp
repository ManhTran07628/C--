#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e9
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e5+7;
const int LOG = 18;
int t,n,q,head[MM],num[MM],heavy[MM],h[MM],up[MM][LOG + 5];
int a[MM],m = 0,tour[MM];
vector<int> adj[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
    if(heavy[u])
        decompose(heavy[u],H);

    for(auto v:adj[u]) {
        if(v != heavy[u] && up[u][0] != v) 
            decompose(v,v);
    }
}

struct Node
{
    int max_n,min_n;
    ll sum1,sum2;
} st[MM * 4];

Node Merge(Node a,Node b)
{
    int max_n = max(a.max_n,b.max_n);
    int min_n = min(a.min_n,b.min_n);
    ll sum1 = a.sum1 + b.sum1;
    ll sum2 = a.sum2 + b.sum2;
    return {max_n,min_n,sum1,sum2};
}

void build(int id,int l,int r)
{
    if(l == r) {
        ll v = a[ tour[l] ];
        st[id] = {v,v,v,v*v};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {val,val,val,1ll*val*val};
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {-oo,oo,0,0};
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return Merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void process()
{
    dfs(1);
    decompose(1,1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
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

bool QueryPath(int u,int v)
{
    Node res = {-oo,oo,0,0};
    int lca = LCA(u,v);

    ll l = h[v] + h[u] - h[lca] * 2 + 1;

    while(head[u] != head[lca]) {
        auto p = get(1,1,n,num[ head[u] ],num[u]);
        res = Merge(p,res);
        u = up[ head[u] ][0];
    }

    while(head[v] != head[lca]) {
        auto p = get(1,1,n,num[ head[v] ],num[v]);
        res = Merge(p,res);
        v = up[ head[v] ][0];
    }

    if(h[u] < h[v]) res = Merge(res,get(1,1,n,num[u],num[v]));
    else res = Merge(res,get(1,1,n,num[v],num[u]));

    ll sum1 = l * (l + 1) / 2;
    ll sum2 = l * (l + 1) * (2*l + 1) / 6;
    // return {l,1,sum1,sum2};
    if(res.max_n == l && res.min_n == 1 && res.sum1 == sum1 && res.sum2 == sum2) return 1;
    return 0;
}

// int t,n,q,head[MM],num[MM],heavy[MM],h[MM],up[MM][LOG + 1];
// int a[MM],m = 0,tour[MM];
// vector<int> adj[MM];

void resetqr()
{
    m = 0;
    for(int i = 0;i <= n;i++) {
        head[i] = 0;
        num[i] = 0;
        heavy[i] = 0;
        h[i] = 0;
        for(int j = 0;j <= LOG;j++) up[i][j] = 0;
        tour[i] = 0;
        adj[i].clear();
    }

}

void solve()
{
    init();
    process();
    build(1,1,n);
    while(q--) {
        int type,x,y;
        cin >> type >> x >> y;
        if(type == 1) {
            // auto res = QueryPath(x,y);
            // cout << res.max_n << ' ' << res.min_n << ' ' << res.sum1 << ' ' << res.sum2 << '\n';
            cout << (QueryPath(x,y) ? "Yes" : "No") << '\n';
        }
        else update(1,1,n,num[x],y);
    }
    resetqr();
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}