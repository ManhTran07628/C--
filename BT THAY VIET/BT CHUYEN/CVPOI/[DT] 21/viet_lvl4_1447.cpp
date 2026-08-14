#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m,active[MM],d[MM],ans[MM];
vector<int> adj[MM];

struct DSU
{
    int par[MM] = {}, sz[MM] = {};

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }

    void active_node(int a)
    {
        active[a] = 1;
        par[a] = a; 
        sz[a] = 1;

        for(auto v:adj[a]) {
            if(!active[v]) continue;
            Unite(a,v);
        }
    }
} g;

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
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) cin >> d[i];

    for(int i = n;i >= 1;i--) {
        g.active_node(d[i]);
        if(g.sz[g.find_sets(d[i])] != n - i + 1) ans[i] = 0;
        else ans[i] = 1;
    }
    for(int i = 1;i <= n;i++) cout << (ans[i] == 0 ? "NO" : "YES") << '\n';
    return 0;
}