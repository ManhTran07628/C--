#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int LOG = 18;
int n,m,up[MM][LOG + 1],Max[MM][LOG + 1],h[MM],vis[MM];
struct Edge{int u,v,w;};
vector<Edge> edges;
map<int,int> isMST;

vector<pii> adj[MM];

struct MST
{
    vector<int> par,sz;
    MST() {
        par.resize(MM);
        for(int i = 1;i < MM;i++) 
            par[i] = i;
    }

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
        return 1;
    }
} g;

void dfs(int u)
{
    vis[u] = 1;
    for(auto N:adj[u]) {
        int v = N.fi, w = N.se;
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        Max[v][0] = w;
        dfs(v);
    }
}

int LCA(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    int ans = 0;
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v]) {
            ans = max(ans,Max[u][i]);
            u = up[u][i];
        }
    
    if(u == v) return ans;

    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i]) {
            ans = max({ans,Max[u][i],Max[v][i]});
            u = up[u][i], v = up[v][i];
        }
    ans = max({ans,Max[u][0],Max[v][0]});
    return ans;
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
    sort(edges.begin(),edges.end(), [] (Edge a,Edge b){
        return a.w > b.w;
    });
    int id = 0;
    for(auto N:edges) {
        id++;
        int u = N.u, v = N.v, w = N.w;
        if(!g.Unite(u,v)) continue;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        isMST[id] = 1;
        // cout << u << ' ' << v << ' ' << w << '\n';
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) dfs(i);
    }
    up[1][0] = 1;
    Max[1][0] = 0;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
            Max[i][j] = max(Max[i][j-1],Max[ up[i][j-1] ][j-1]);
        }

    ll res = 0;
    id = 0;
    for(auto N:edges) {
        id++;
        int u = N.u, v = N.v, w = N.w;
        if(isMST[id]) continue;
        res = max(res,(ll) LCA(u,v) + w);
        // cout << u << ' ' << v << ' ' << w << ' ' << LCA(u,v) << '\n';
    }
    cout << res;

    return 0;
}
