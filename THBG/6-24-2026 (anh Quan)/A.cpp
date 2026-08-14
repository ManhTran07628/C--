#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,q;

struct DSU
{
    int par[MM] = {}, sz[MM] = {};
    vector<pii> snapshot;

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

    bool Unite(int u,int v)
    {
        u = find_sets(u);
        v = find_sets(v);
        if(u == v) return 0;
        if(sz[v] > sz[u]) swap(u,v);

        snapshot.push_back({u,v});
        sz[u] += sz[v];
        par[v] = u;
        
        return 1;
    }

    void rollback()
    {
        pii c = snapshot.back();
        snapshot.pop_back();

        int u = c.fi, v = c.se;
        // u la cha cua v
        sz[u] -= sz[v];
        par[v] = v;

    }
} g;

vector<pii> st[MM * 4];
map<pii,int> last;
int cnt = 0;
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

void get(int id,int l,int r)
{
    int sz = g.snapshot.size();

    for(auto edge: st[id]) {
        int u = edge.fi, v = edge.se;
        if(g.Unite(u,v)) cnt++;
    }

    if(l == r) {
        ans[l] = n - cnt;
        while(g.snapshot.size() > sz) {
            g.rollback();
            cnt--;
        }
        return;
    }

    int mid = (l + r) / 2;
    get(id*2,l,mid);
    get(id*2+1,mid+1,r);

    while(g.snapshot.size() > sz) {
        g.rollback();
        cnt--;
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
    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        if(u > v) swap(u,v);
        last[{u,v}] = 0;
    }
    g.build();
    for(int i = 1;i <= q;i++) {
        int t,a,b; cin >> t >> a >> b;
        if(a > b) swap(a,b);
        if(t == 1) {
            last[{a,b}] = i;
        }
        else {
            update(1,0,q,last[{a,b}],i - 1,{a,b});
            last.erase({a,b});
        }
    }

    for(auto edge:last) {
        int a = edge.fi.fi, b = edge.fi.se;
        int pos = edge.se;
        update(1,0,q,pos,q,{a,b});
    }

    get(1,0,q);


    for(int i = 0;i <= q;i++) cout << ans[i] << ' ';
    return 0;
}