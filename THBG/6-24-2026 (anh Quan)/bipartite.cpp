#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,q;
// vector<pii> edges;

struct DSU
{
    int par[MM] = {}, sz[MM] = {}, d[MM] = {};
    bool isBipartite = 1;

    struct Snapshot
    {
        int u;
        int v;
        bool is_Bipartite;
    };

    vector<Snapshot> snapshot;

    void build()
    {
        for(int i = 1;i < MM;i++) {
            par[i] = i; d[i] = 0;
            sz[i] = 1;
        }
    }

    pii find_sets(int a)
    {
        int f = 0;
        while(a != par[a]) {
            f ^= d[a];
            a = par[a];
        }
        return {a, f};
    }

    void Unite(int a,int b)
    {
        pii A = find_sets(a);
        pii B = find_sets(b);

        if(A.fi == B.fi) {
            snapshot.push_back({0,0,isBipartite});
            if(A.se == B.se) isBipartite = 0;
            return;
        }
        else {
            if(sz[B.fi] > sz[A.fi]) swap(A,B);
            snapshot.push_back({A.fi,B.fi,isBipartite});
            par[B.fi] = A.fi;
            sz[A.fi] += sz[B.fi];
            d[B.fi] = (A.se + B.se + 1) % 2;
        }
    }

    void rollback()
    {
        Snapshot c = snapshot.back();
        snapshot.pop_back();
        int u = c.u, v = c.v;
        par[v] = v;
        sz[u] -= sz[v];
        isBipartite = c.is_Bipartite;
        d[v] = 0;
    }
} g;


int ans[MM];
vector<pii> st[MM * 4];
map<pii,int> last_pos;

void update(int id,int l,int r,int u,int v,pii c)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id].push_back(c);
        return;
    }

    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,c);
    update(id*2+1,mid+1,r,u,v,c);
}

void get(int id,int l,int r)
{
    int sz = g.snapshot.size();
    for(auto E:st[id]) {
        int u = E.fi, v = E.se;
        g.Unite(u,v);
    }

    if(l == r) {
        ans[l] = g.isBipartite;

        while(g.snapshot.size() > sz) {
            g.rollback();
        }

        return;
    }

    int mid = (l + r) / 2;
    get(id*2,l,mid);
    get(id*2+1,mid+1,r);

    while(g.snapshot.size() > sz) {
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

    g.build();

    for(int i = 1;i <= q;i++) {
        int x,y; cin >> x >> y;
        if(x > y) swap(x,y);
        if(last_pos.find({x,y}) == last_pos.end()) {
            last_pos[{x,y}] = i;
        }
        else {
            update(1,1,q,last_pos[{x,y}],i - 1,{x,y});
            last_pos.erase({x,y});
        }
    }

    for(auto E:last_pos) {
        int u = E.fi.fi, v = E.fi.se;
        int pos = E.se;
        update(1,1,q,pos,q,{u,v});
    }

    get(1,1,q);
    
    for(int i = 1;i <= q;i++) cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}