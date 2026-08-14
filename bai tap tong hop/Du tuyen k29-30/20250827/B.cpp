#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 1e5+7;
int n,m,p[MM];

struct Edge
{
    int u,v,w;
};
vector<Edge> edges;


struct DSU
{
    vector<int> par,sz;
    DSU(int n) : par(n+7),sz(n+7) {};
    
    void make_sets()
    {
        for(int i = 1;i <= n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    void unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        par[b] = a;
    }
};
DSU g(MM);

void init()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> p[i];
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
}


bool check(int k)
{
    g.make_sets();
    for(auto E:edges) {
        int u = E.u, v = E.v, w = E.w;
        if(w >= k) g.unite(u,v);
    }
    for(int i = 1;i <= n;i++) {
        if(g.find_sets(p[i]) != g.find_sets(i)) return 0;
    }
    return 1;
}

void solve()
{
    int l = 1,r = 1e9,ans = -1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << (ans != oo ? ans : -1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "wormsort"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    solve();
    return 0;
}