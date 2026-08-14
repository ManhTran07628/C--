#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int LOG = 17;
int n,m,head[MM],num[MM],heavy[MM],up[MM][LOG+1],h[MM];
int q;
vector<int> adj[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
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
        if(max_sz < child_sz) {
            max_sz = child_sz;
            heavy[u] = v;
        }
    }
    return cur_sz;
}

void decompose(int u,int H)
{
    num[u] = ++m; head[u] = H;
    if(heavy[u]) decompose(heavy[u],H);

    for(auto v:adj[u]) {
        if(v != up[u][0] && v != heavy[u])
            decompose(v,v);
    }
}

int st[MM*4],lazy[MM*4];

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

void update(int id,int l,int r,int u,int v,int val)
{
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

void UpdateQuery(int u,int v,int val)
{
    int lca = LCA(u,v);
    while(head[u] != head[lca]) {
        update(1,1,n,num[ head[u] ],num[u]-1,val);
        u = up[ head[u] ][0];
    }
    while(head[v] != head[lca]) {
        update(1,1,n,num[ head[v] ],num[v]-1,val);
        v = up[ head[v] ][0];
    }
    if(num[u] > num[v]) swap(u,v);
    update(1,1,n,num[u],num[v]-1,val);
}

int GetQuery(int u,int v)
{
    int lca = LCA(u,v);
    int ans = 0;
    while(head[u] != head[lca]) {
        ans += get(1,1,n,num[ head[u] ],num[u]-1);
        u = up[ head[u] ][0];
    }
    while(head[v] != head[lca]) {
        ans += get(1,1,n,num[ head[v] ],num[v]-1);
        v = up[ head[v] ][0];
    }
    if(num[u] > num[v]) swap(u,v);
    ans += get(1,1,n,num[u],num[v]-1);
    return ans;
}

void solve()
{
    dfs(1);
    decompose(1,1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
    // for(int i = 1;i <= n;i++) cout << i << ' ' << head[i] << ' ' << num[i] << '\n';
    while(q--) {
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c == 'P') UpdateQuery(a,b,1);
        else cout << GetQuery(a,b) << '\n';
    }   
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}