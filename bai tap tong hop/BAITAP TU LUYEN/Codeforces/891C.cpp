#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,q,L[MM],R[MM],ans[MM];
struct Edge{int u,v,w,id;};
vector<Edge> edges;
vector<pii> adj[MM];

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

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) {
            snapshot.push_back({0,0});
            return;
        }
        if(sz[a] < sz[b]) swap(a,b);
        snapshot.push_back({a,b});
        par[b] = a;
        sz[a] += sz[b];
    }

    void rollback()
    {
        pii c = snapshot.back();
        snapshot.pop_back();
        int a = c.fi, b = c.se;
        if(a == 0 && b == 0) return;
        sz[a] -= sz[b];
        par[b] = b;
    }
} g;

void dnc(int L,int R)
{
    if(L == R) {
        int u = edges[L].u, v = edges[L].v, id = edges[L].id;
        if(g.find_sets(u) != g.find_sets(v)) ans[id] = 1;
        return;
    }

    int mid = (L + R) / 2;

    int sz = g.snapshot.size();
    for(int i = mid + 1;i <= R;i++) 
        g.Unite(edges[i].u,edges[i].v);

    dnc(L,mid);
    while(g.snapshot.size() > sz) g.rollback();
    
    sz = g.snapshot.size();
    for(int i = L;i <= mid;i++) 
        g.Unite(edges[i].u,edges[i].v);
    
    dnc(mid + 1,R);
    while(g.snapshot.size() > sz) g.rollback();
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
    fill(L+1,L+MM,oo);
    memset(ans,-1,sizeof(ans));
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w,i});
    }
    g.build();
    sort(edges.begin(),edges.end(), [] (Edge a,Edge b){return a.w < b.w;});
    
    for(int i = 0;i < edges.size();i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        L[w] = min(L[w],i);
        R[w] = max(R[w],i);
    }

    for(int i = 0;i < edges.size();) {
        int cur_w = edges[i].w;
        dnc(L[cur_w],R[cur_w]);
        
        for(int j = L[cur_w];j <= R[cur_w];j++) {
            int u = edges[j].u, v = edges[j].v, id = edges[j].id;
            g.Unite(u,v);
        }
        
        i = R[cur_w] + 1;
    }

    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';
    // cin >> q;
    // while(q--) {
    //     int k; cin >> k;
    //     int res = 1;
    //     while(k--) {
    //         int u;
    //         res &= ans[u];
    //     }
    //     cout << (res ? "YES" : "NO") << '\n';
    // }

    return 0;
}