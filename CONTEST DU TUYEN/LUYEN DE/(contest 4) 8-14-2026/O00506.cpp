#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e3 + 7;
int n,m,k,p[MM],c[MM];

vector<pii> edges;

namespace subtask1
{
    vector<int> adj[MM];
    vector<int> project;
    ll res = 0;

    void check()
    {
        map<int,int> mp;
        ll profit = 0, cost = 0;
        for(auto id:project) {
            profit += p[id];

            for(auto j:adj[id]) 
                if(mp.find(j) == mp.end()) {
                    mp[j] = 1;
                    cost += c[j];
                }
            
        }

        res = max(res,profit - cost);
    }

    void Try(int id)
    {
        if(id > n) {
            if(project.empty()) return;
            check();
            return;
        }

        project.push_back(id);
        Try(id + 1);
        project.pop_back();

        Try(id + 1);
    }

    void solve()
    {
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            adj[u].push_back(v);
        }
        Try(1);
        cout << res;
    }
}

namespace subtask2 // k == n
{
    ll dp[MM];
    vector<int> adj[MM];
    void solve()
    {
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            adj[v].push_back(u);
        }

        for(int i = 1;i <= m;i++) {
            ll profit = 0;
            for(auto j:adj[i]) {
                profit += p[j];
            }
            dp[i] = max(0ll,profit - c[i]) + dp[i - 1];
        }
        cout << dp[m];
    }
}

namespace subtask3
{
    ll dp[1 << 20];
    vector<int> adj[MM];
    ll g[1 << 20];
    void solve()
    {
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            adj[u].push_back(--v);
        }

        for(int i = 1;i <= n;i++) {
            int mask = 0;
            for(auto j:adj[i]) {
                mask |= (1 << j);
            }

            dp[mask] += p[i];
        }

        for(int i = 0;i < m;i++) {
            for(int mask = 0;mask < (1 << m);mask++) {
                if(mask >> i & 1) 
                    dp[mask] += dp[mask ^ (1 << i)];
            }
        }

        ll res = 0;
        for(int mask = 0;mask < (1 << m);mask++) {
            ll cost = 0;
            for(int i = 0;i < m;i++) 
                if(mask >> i & 1) cost += c[i + 1];
            res = max(res,dp[mask] - cost);
        }

        cout << res;
    }
}

namespace subtask4
{
    vector<int> adj[MM];
    int source,sink;

    ll d[MM] = {}, cnt_id[MM] = {};
    ll f[MM][MM] = {};

    void bfs()
    {
        fill(d,d+sink+1,oo);
        d[source] = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto v:adj[u]) {
                if(d[v] != oo || f[u][v] == 0) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    ll dfs(int u,ll cur_delta)
    {
        if(cur_delta == 0) return 0;
        if(u == sink) return cur_delta;
        for(;cnt_id[u] < adj[u].size();cnt_id[u]++) {
            int v = adj[u][ cnt_id[u] ];
            if(d[v] != d[u] + 1 || f[u][v] == 0) continue;

            ll delta = dfs(v, min(cur_delta,f[u][v]));
            if(delta == 0) continue;

            f[u][v] -= delta;
            f[v][u] += delta;

            return delta;
        }
        return 0;
    }

    void solve()
    {
        source = 0, sink = n + m + 1; //cout << sink << '\n';
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            v += n;

            f[source][u] = p[u];
            f[v][sink] = c[v - n];
            f[u][v] = oo;

            adj[source].push_back(u);
            adj[u].push_back(v);
            adj[v].push_back(sink);
            
            adj[u].push_back(source);
            adj[v].push_back(u);
            adj[sink].push_back(v);

            // cout << source << ' ' << u << ' ' << v << ' ' << sink << '\n';
        }

        ll max_flow = 0, profit = 0;

        for(int i = 1;i <= n;i++) profit += p[i];

        while(1) {
            fill(cnt_id,cnt_id+sink+1,0);
            bfs();
            // for(int i = 0;i <= sink;i++) cout << i << ' ' << d[i] << '\n';
            if(d[sink] == oo) break;


            // cout << 36 << '\n';
            while(ll delta = dfs(source,oo)) {
                max_flow += delta;
                // cout << delta << '\n';
            }
        }
        
        // cout << max_flow;
        cout << profit - max_flow;
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
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> p[i];
    for(int i = 1;i <= m;i++) cin >> c[i];
    for(int i = 1;i <= k;i++) {
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
    }
    subtask4::solve();
    // if(n <= 20) subtask1::solve();
    // else if(m <= 20) subtask3::solve();
    // else subtask2::solve();
    return 0;
}