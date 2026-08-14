#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,q;
struct QR{char type;int u,v,id;} qr[MM];

struct DSU
{
    int par[MM] = {}, sz[MM] = {};

    struct Snapshot{int a,b,old_b,sz_b;};
    vector<Snapshot> snapshot;

    void build()
    {
        for(int i = 1;i < MM;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return find_sets(par[a]);
    }

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) {
            snapshot.push_back({0,0,0,0});
            return;
        }
        if(sz[a] < sz[b]) swap(a,b);

        snapshot.push_back({a,b,par[b],sz[b]});
        par[b] = a;
        sz[a] += sz[b];
    }

    void rollback()
    {
        int a = snapshot.back().a, b = snapshot.back().b;
        int old_b = snapshot.back().old_b, sz_b = snapshot.back().sz_b;
        snapshot.pop_back();

        if(a == 0 && b == 0) return;

        sz[a] -= sz_b;
        par[b] = old_b;

    }
} g;  

map<pii,int> mp;
int cur_id = 0;

vector<pii> st[MM * 4];
pii askqueries[MM] = {};
int ans[MM];

void update(int id,int l,int r,int u,int v,pii edge)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id].push_back(edge);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,edge);
    update(id*2+1,mid+1,r,u,v,edge);
}

void dfs(int id,int l,int r)
{
    int sz = g.snapshot.size();
    for(auto edges:st[id]) {
        int u = edges.fi, v = edges.se;
        g.Unite(u,v);
    }

    if(l == r) {
        pii edge = askqueries[l];
        int u = edge.fi, v = edge.se;
        if(u != 0 && v != 0 && g.find_sets(u) == g.find_sets(v)) {
            ans[l] = 1;
        }

        while(g.snapshot.size() != sz) {
            g.rollback();
        }
        return;
    }

    int mid = (l + r) / 2;
    dfs(id*2,l,mid);
    dfs(id*2+1,mid+1,r);

    while(g.snapshot.size() != sz) {
        g.rollback();
    }
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
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].type >> qr[i].u >> qr[i].v;
    }

    g.build();
    for(int i = 1;i <= q;i++) {
        int u = qr[i].u, v = qr[i].v;
        if(u > v) swap(u,v);

        if(qr[i].type == '+') mp[{u,v}] = i;
        else if(qr[i].type == '-') {
            int l = mp[{u,v}];
            int r = i - 1;
            update(1,1,q,l,r,{u,v});
            mp.erase({u,v});
        }
        else if(qr[i].type == '?') askqueries[i] = {u,v};
    }

    for(auto edge:mp) {
        int u = edge.fi.fi, v = edge.fi.se;
        int st = edge.se;
        update(1,1,q,st,q,{u,v});
    }

    dfs(1,1,q);
    for(int i = 1;i <= q;i++) {
        if(qr[i].type == '?') cout << (ans[i] ? "YES" : "NO") << '\n';
    }
    
    return 0;
}