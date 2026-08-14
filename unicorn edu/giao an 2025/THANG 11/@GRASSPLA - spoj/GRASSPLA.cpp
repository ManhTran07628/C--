#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int LOG = 16;
int n,q,up[MM][LOG + 1],h[MM],head[MM],heavy[MM],num[MM];
int tour[MM],m = 0;
vector<int> adj[MM];
struct Edge{int u,v;} edges[MM];

int dfs(int u) {
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

    for(auto v:adj[u]) 
        if(v != heavy[u] && up[u][0] != v)
            decompose(v,v);
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

int st[MM * 4],lazy[MM * 4];

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] += (r - l + 1) * lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id]++;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
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

void UpdateQuery(int u,int v)
{
    int lca = LCA(u,v);
    while(head[u] != head[lca]) {
        update(1,1,n,num[ head[u] ],num[u]);
        u = up[ head[u] ][0];
    }
    if(u != lca) {
        update(1,1,n,num[lca] + 1,num[u]);
    }

    while(head[v] != head[lca]) {
        update(1,1,n,num[ head[v] ],num[v]);
        v = up[ head[v] ][0];
    }
    if(v != lca) {
        update(1,1,n,num[lca] + 1,num[v]);
    }
}

int GetQuery(int u,int v)
{
    int lca = LCA(u,v);
    int res = 0;
    while(head[u] != head[lca]) {
        res += get(1,1,n,num[ head[u] ],num[u]);
        u = up[ head[u] ][0];
    }
    if(u != lca) {
        res += get(1,1,n,num[lca] + 1,num[u]);
    }

    while(head[v] != head[lca]) {
        res += get(1,1,n,num[ head[v] ],num[v]);
        v = up[ head[v] ][0];
    }
    if(v != lca) {
        res += get(1,1,n,num[lca] + 1,num[v]);
    }
    return res;
}

void solve()
{
    process();


    while(q--) {
        char type;
        int u,v;
        cin >> type >> u >> v;
        if(type == 'P') UpdateQuery(u,v);
        else cout << GetQuery(u,v) << '\n';
    }
    // cout << GetQuery(1,4);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u,v};
    }
    solve();


    return 0;
}