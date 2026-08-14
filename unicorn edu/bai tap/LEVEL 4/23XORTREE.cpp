#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int LOG = 17;
int n,q,tour[MM],heavy[MM],head[MM],num[MM],up[MM][LOG + 3],a[MM];
int h[MM],m = 0;
vector<int> adj[MM];
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
    head[u] = H;
    tour[++m] = u;
    num[u] = m;
    if(heavy[u])
        decompose(heavy[u],H);
    for(auto v:adj[u]) {
        if(v != heavy[u] && up[u][0] != v) 
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
    st[id] = st[id*2] ^ st[id*2+1];
}

void update(int id,int l,int r,int pos,int val)
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

ll getQuery(int u,int v)
{
    int lca = LCA(u,v);
    ll res = 0;
    while(head[lca] != head[u]) {
        ll cur = get(1,1,n,num[ head[u] ],num[u]);
        res ^= cur;
        u = up[ head[u] ][0];
    }

    // if(u != lca) res ^= get(1,1,n,num[lca],num[u]);

    while(head[lca] != head[v]) {
        ll cur = get(1,1,n,num[ head[v] ],num[v]);
        res ^= cur;
        v = up[ head[v] ][0];
    }

    if(num[u] < num[v]) res ^= get(1,1,n,num[u],num[v]);
    else res ^= get(1,1,n,num[v],num[u]);

    // if(v != lca) res ^= get(1,1,n,num[lca],num[v]);

    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    process();
    // for(int i = 1;i <= n;i++) update(1,1,n,num[i],a[i]);
    build(1,1,n);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u,x;
            cin >> u >> x;
            update(1,1,n,num[u],x);
        }
        else {
            int u,v;
            cin >> u >> v;
            cout << getQuery(u,v) << '\n';
        }
    }
    return 0;
}