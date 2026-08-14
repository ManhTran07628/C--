#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e3 + 7;
int n,m,s,t,c[MM][MM],f[MM][MM],d[MM],cur_id[MM];
vector<int> adj[MM];

void bfs()
{
    queue<int> q;
    q.push(s);
    fill(d+1,d+n+1,oo);
    d[s] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(f[u][v] == 0 || d[v] != oo) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int dfs(int u,int cur_delta)
{
    if(cur_delta == 0) return 0;
    if(u == t) return cur_delta;

    for(;cur_id[u] < adj[u].size(); cur_id[u]++) {
        int v = adj[u][ cur_id[u] ];

        if(d[v] != d[u] + 1 || f[u][v] == 0) continue;

        int delta = dfs(v, min(cur_delta,f[u][v]));
        if(delta == 0) continue;
        f[u][v] -= delta;
        f[v][u] += delta;
        return delta;
    }
    return 0;
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
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        cin >> c[u][v];
        f[u][v] = c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_flow = 0;

    while(1) {
        bfs();
        if(d[t] == oo) break;
        for(int i = 1;i <= n;i++) cur_id[i] = 0;
        while(int delta = dfs(s,oo)) 
            max_flow += delta;
    }
    cout << max_flow;

    return 0;
}