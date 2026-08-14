#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e6 + 7;
int n,m,ans[MM],L[MM],R[MM];
struct Edge{int u,v,w,id;};
vector<Edge> edges;

// -1 none state  0 - none    1 - at least one    2 - any
struct DSU
{
    int par[MM] = {}, sz[MM] = {};
    
    struct Snapshot
    {
        int u,v;
    };

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

    bool Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        if(sz[a] < sz[b]) swap(a,b);
        snapshot.push_back({a,b});
        sz[a] += sz[b];
        par[b] = a;
        return 1;
    }

    void rollback()
    {
        Snapshot c = snapshot.back();
        snapshot.pop_back();
        int u = c.u, v = c.v;
        sz[u] -= sz[v];
        par[v] = v;
    }

} g;

void dnc(int l,int r)
{
    if(l == r) {
        Edge E = edges[l - 1];
        int u = E.u, v = E.v;
        if(g.find_sets(u) != g.find_sets(v)) ans[E.id] = 2;
        return;
    }

    int mid = (l + r) / 2;

    int sz = g.snapshot.size();
    for(int i = mid + 1;i <= r;i++) g.Unite(edges[i - 1].u,edges[i - 1].v);
    dnc(l,mid);
    while(g.snapshot.size() > sz) {
        g.rollback();
    }

    for(int i = l;i <= mid;i++) g.Unite(edges[i - 1].u,edges[i - 1].v);
    dnc(mid+1,r);
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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w,i});
    }

    memset(ans,-1,sizeof(ans));

    g.build();
    sort(edges.begin(),edges.end(), [] (Edge a, Edge b){return a.w < b.w;});

    for(int i = 1;i < MM;i++) L[i] = oo, R[i] = 0;

    for(int i = 0;i < edges.size();i++) {
        auto E = edges[i]; int u = E.u, v = E.v, w = E.w, id = E.id;
        L[w] = min(L[w],i + 1);
        R[w] = max(R[w],i + 1);
        // cout << u << ' ' << v << ' ' << w << ' ' << id << '\n';
    }
    
    
    for(int i = 0;i < edges.size();) {
        for(int j = i;j < R[ edges[i].w ];j++) {
            auto E = edges[j]; int u = E.u, v = E.v, w = E.w, id = E.id;
            if(g.find_sets(u) == g.find_sets(v)) ans[id] = 0;
        }

        dnc(L[ edges[i].w ],R[ edges[i].w ]);

        for(int j = i;j < R[ edges[i].w ];j++) {
            auto E = edges[j]; int u = E.u, v = E.v, w = E.w, id = E.id;
            if(!g.Unite(u,v)) continue;
        }

        i = R[ edges[i].w ];
    }



    for(int i = 1;i <= m;i++) {
        if(ans[i] == 0) cout << "none";
        if(ans[i] == -1) cout << "at least one";
        if(ans[i] == 2) cout << "any";
        cout << '\n';
    }

    return 0;
}