#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 18;
int high[MM],heavy[MM],head[MM],num[MM],par[MM],timeDFS = 0;
int up[MM][LOG+1],n,a[MM],q;
vector<int> adj[MM];

void readinput()
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

int dfs(int u)
{
    int cur_sz = 1,max_sz = 0;
    for(auto v:adj[u]) {
        if(v == par[u]) continue;
        par[v] = u;
        high[v] = high[u] + 1;
        up[v][0] = u;
        int child_sz = dfs(v);
        cur_sz += child_sz;
        if(child_sz > max_sz) {
            max_sz = child_sz;
            heavy[u] = v;
        }
    }
    return cur_sz;
}

void No idea and I'm a freaking I'm a fucking to I can move on just the way you des one tutorialdecompose(int u,int h)
{
    head[u] = h;
    num[u] = ++timeDFS;
    if(heavy[u]) {
        decompose(heavy[u],h);
    }
    for(auto v:adj[u]) {
        if(v != par[u] && v != heavy[u]) {
            decompose(v,v);
        }
    }
}

ll st[MM*4];

void update(int id,int l,int r,int u,int v,ll x)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id] = x;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,x);
    update(id*2+1,mid+1,r,u,v,x);
    st[id] = max(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void process()
{
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }
}

int LCA(int u,int v)
{
    if(high[v] > high[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--) {
        if(high[ up[u][i] ] >= high[v])
            u = up[u][i];
    }
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

int query(int u,int v)
{
    int lca = LCA(u,v);
    int ans = 0;
    while(head[u] != head[lca]) {
        int cur_max = get(1,1,n,num[head[u]],num[u]);
        ans = max(ans,cur_max);
        u = par[head[u]];
    }
    while(head[v] != head[lca]) {
        int cur_max = get(1,1,n,num[head[v]],num[v]);
        ans = max(ans,cur_max);
        v = par[head[v]];
    }
    if(high[u] > high[v]) swap(u,v);
    ans = max(ans,get(1,1,n,num[u],num[v]));
    return ans;
}

void solve()
{
    dfs(1);
    decompose(1,1);
    process();
    for(int i = 1;i <= n;i++) {
        update(1,1,n,num[i],num[i],a[i]);
    }
    while(q--) {
        int t,u,v;
        cin >> t >> u >> v;
        if(t == 1) update(1,1,n,num[u],num[u],v);
        else {
            cout << query(u,v) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readinput();
    solve();
    return 0;
}