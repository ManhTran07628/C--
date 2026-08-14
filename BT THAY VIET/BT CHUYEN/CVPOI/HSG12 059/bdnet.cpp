#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,max_sz = 0;
ll res = 0;
struct Edge{int u,v,w;};
vector<Edge> edges;

struct DSU
{
    int par[MM] = {}, sz[MM] = {};

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    bool Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        par[b] = a;
        sz[a] += sz[b];
        max_sz = max(max_sz,sz[a]);
        return 1;
    }
} g;

bool cmp(Edge a,Edge b)
{
    return a.w > b.w;
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
        edges.push_back({u,v,w});
    }
    for(int i = 1;i <= n;i++) {
        g.par[i] = i;
        g.sz[i] = 1;
    }
    sort(edges.begin(),edges.end(),cmp);
    for(auto E:edges) {
        // cout << E.u << ' ' << E.v << ' ' << E.w << '\n';
        if(!g.Unite(E.u,E.v)) continue;
        res += E.w;
    }
    if(max_sz == n) cout << res;
    else cout << -1;
    // cout << max_sz << ' ' << res;
    // cout << res;
    return 0;
}