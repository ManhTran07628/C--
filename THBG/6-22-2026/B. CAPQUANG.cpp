#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 3e5 + 7;
int n,m,R[MM],d[MM];
vector<int> adj[MM];

struct Edges{int u,v,w,id;};

vector<Edges> edges;

struct DSU
{
    int par[MM] = {};
 
    void build(int n)
    {
        for(int i = 1;i <= n;i++)
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
 
namespace subtask1
{
    int is_mst[MM];
    vector<Edges> cur;
 
    bool cmp(Edges a,Edges b)
    {
        return a.w < b.w;
    }
 
    void solve()
    {       
        string perm,res = "a";
        for(int i = 1;i <= m;i++) {
            char c = i + '0';
            perm.push_back(c);
        }
        do 
        {
            for(int i = 1;i <= m;i++) is_mst[i] = 0;
            for(int i = 0;i < m;i++) cur = edges;
            for(int i = 0;i < m;i++) cur[i].w = perm[i] - '0';
 
            g.build(m);
            sort(cur.begin(),cur.end(),cmp);
 
            for(auto E:cur) {
                int u = E.u, v = E.v, id = E.id;
                if(!g.Unite(u,v)) continue;
                is_mst[id] = 1;
            }

            
 
            bool ok = 1;
            for(int i = 1;i <= n;i++) {
                if(R[i] && !is_mst[i]) ok = 0;
            }
            if(ok) {
                res = min(res,perm);
            }
        }
        while(next_permutation(perm.begin(),perm.end()));
 
        for(auto e:res) cout << e << ' ';
    }
}

namespace subtask2
{
    const int LOG = 18;
    int ans[MM],h[MM],up[MM][LOG + 1],vis[MM];

    void dfs(int u)
    {
        for(auto v:adj[u]) {
            if(up[u][0] == v) continue;
            h[v] = h[u] + 1;
            up[v][0] = u;
            dfs(v);
        }
    }

    int lca(int u,int v)
    {
        if(h[u] < h[v]) swap(u,v);
        for(int j = LOG;j >= 0;j--)
            if(h[ up[u][j] ] >= h[v])
                u = up[u][j];
        if(u == v) return u;
        for(int j = LOG;j >= 0;j--)
            if(up[u][j] != up[v][j])
                u = up[u][j], v = up[v][j];
        return up[u][0];
    }

    int get(int u,int v)
    {
        int lck = lca(u,v);
        int cnt = 0, max_val = oo;
        while(u != lck) {
            if(ans[u] != oo) max_val = min(max_val,ans[u]);
            else cnt++;
            u = up[u][0];
        }
        while(v != lck) {
            if(ans[v] != oo) max_val = min(max_val,ans[v]);
            else cnt++;
            v = up[v][0];
        }
        vis[cnt + 1] = 1;
        return cnt + 1;
    }

    void solve()
    {
        dfs(1);
        up[1][0] = 1;
        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i <= n;i++)
                up[i][j] = up[ up[i][j-1] ][j-1];

        
        for(int i = 1;i <= m;i++) ans[i] = oo;
        int cur = n;
        for(int i = m;i >= 1;i--) {
            auto Edge = edges[i - 1];
            int u = Edge.u, v = Edge.v;

            int child = (up[u][0] == v ? u : v);

            if(R[i]) {
                while(vis[cur]) cur--;
                ans[child] = cur;
                cout << cur << ' ';
                vis[cur] = 1;
            }
            else cout << get(u,v) << ' ';
        }

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
        int u,v; cin >> u >> v;
        edges.push_back({u,v,0,i});
    }

    for(int i = 1;i <= n - 1;i++) {
        int id; cin >> id;
        d[i] = id;
        R[id] = 1;
        auto Edge = edges[id - 1];
        int u = Edge.u, v = Edge.v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    subtask2::solve();
    return 0;
}