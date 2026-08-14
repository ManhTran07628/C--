#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m;
string s;
vector<pii> edges;


namespace subtask1
{
    const int M1 = 100 + 7;
    int adj[M1][M1] = {}, vis[M1] = {}, del[M1] = {};
    ll cnt = 0;

    void dfs(int u)
    {
        vis[u] = 1;
        cnt++;
        for(int i = 1;i <= n;i++) {
            if(vis[i] || del[i]) continue;
            if(adj[u][i]) {
                dfs(i);
            }
        }
    }

    ll count_connected_node()
    {
        ll connected = 0;
        for(int i = 1;i <= n;i++) vis[i] = 0;
        for(int i = 1;i <= n;i++) {
            if(del[i]) continue;
            if(!vis[i]) {
                dfs(i);
                connected += cnt * (cnt - 1) / 2;
                cnt = 0;
            }
        }
        return connected;
    }

    void solve()
    {
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            adj[u][v] = adj[v][u] = 1;
        }


        for(int i = 0;i < n;i++) {

            cout << count_connected_node() << '\n';

            int t = i + 1, type = s[i] - '0';
            if(type == 0) {
                for(int v = 1;v <= n;v++) adj[t][v] = 0;
            }
            else {
                vector<int> vec;
                for(int v = 1;v <= n;v++) if(adj[t][v] && !del[v]) vec.push_back(v);

                for(auto u:vec) for(auto v:vec) {
                    if(u == v) continue;
                    adj[u][v] = 1;
                }
                for(int v = 1;v <= n;v++) adj[t][v] = 0;
            }
            del[t] = 1;
        }

    }
}

namespace subtask2
{
    ll connected = 0;
    struct DSU
    {
        int par[MM] = {}, sz[MM] = {};

        void build()
        {
            for(int i = 1;i < MM;i++) {
                par[i] = i;
                sz[i] = 0;
            }
        }

        int find_sets(int a)
        {
            if(a == par[a]) return a;
            return par[a] = find_sets(par[a]);
        }

        void update(int a)
        {
            a = find_sets(a);
            connected += sz[a];
            sz[a]++;
        }

        void Unite(int a,int b)
        {
            a = find_sets(a);
            b = find_sets(b);
            if(a == b) return;
            if(sz[a] < sz[b]) swap(a,b);
            connected += sz[a] * sz[b];
            par[b] = a;
            sz[a] += sz[b];
        }
    } g;

    vector<int> adj[MM];
    ll ans[MM] = {}, vis[MM] = {};
    void solve()
    {
        g.build();
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 1;i <= n;i++) {
            if(s[i - 1] == '1') {
                for(auto v:adj[i]) {
                    if(s[v - 1] == '1')
                    g.Unite(i,v);
                }
            }
        }   
        for(int i = n;i >= 1;i--) {
            int t = i;

            if(s[i - 1] == '1') {
                g.update(i);
            }
            else {
                for(auto v:adj[t]) {
                    if(!vis[v]) continue;
                    g.Unite(t,v);
                }
            }
            vis[t] = 1;
            ans[t] = connected;
        }

        for(int i = 1;i <= n;i++) cout << ans[i] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
    }
    if(n <= 100) subtask1::solve();
    else subtask2::solve();
    return 0;
}
