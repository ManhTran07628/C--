#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7, LOG = 18;
int n,m = 0,head[MM],heavy[MM],num[MM],h[MM],up[MM][LOG + 1],q;
vector<int> adj[MM];

int dfs(int u,int par)
{
    int cur_sz = 1, max_sz = 0;
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        int child_sz = dfs(v,u);
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
    num[u] = ++m; head[u] = H;
    if(heavy[u])
        decompose(heavy[u],H);

    for(auto v:adj[u]) {
        if(v != up[u][0] && v != heavy[u])
            decompose(v,v);
    }
}

struct ST
{
    int st[MM * 4] = {}, lazy[MM * 4] = {};

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
        int mid = (l + r) / 2;
        update(id*2,l,mid,u,v);
        update(id*2+1,mid+1,r,u,v);
        st[id] = st[id*2] + st[id*2+1];
    }

    int get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }
} g;

void update(int u,int v)
{
    while(head[u] != head[v]) {
        if(h[ head[v] ] > h[ head[u] ]) {
            swap(u,v);
        }

        g.update(1,1,n,num[ head[u] ],num[u]);

        u = up[ head[u] ][0];
    }

    if(h[u] < h[v]) swap(u,v);
    g.update(1,1,n,num[v] + 1,num[u]);
}

int get(int u,int v)
{
    int res = 0;
    while(head[u] != head[  v]) {
        if(h[ head[v] ] > h[ head[u] ]) {
            swap(u,v);
        }

        res += g.get(1,1,n,num[ head[u] ],num[u]);

        u = up[ head[u] ][0];
    }

    if(h[u] < h[v]) swap(u,v);
    res += g.get(1,1,n,num[v] + 1,num[u]);
    return res;
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
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    decompose(1,1);

    while(q--) {
        char type; cin >> type;
        if(type == 'P') {
            int u,v; cin >> u >> v;
            update(u,v);
        }
        else {
            int u,v; cin >> u >> v;
            cout << get(u,v) << '\n';
        }
    }

    return 0;
}