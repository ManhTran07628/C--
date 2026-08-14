#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 4e3 + 7;
const int offset = 2e3;
int n,m,s,v,x[MM],y[MM],st,en,cur_id[MM],d[MM];
int f[MM][MM],a[MM],b[MM];
vector<int> adj[MM];


void bfs()
{
    fill(d+1,d+en+1,oo);
    d[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(d[v] != oo || f[u][v] == 0) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int dfs(int u,int cur_delta)
{
    if(cur_delta == 0) return 0;
    if(u == en) return cur_delta;
    for(; cur_id[u] < adj[u].size(); cur_id[u]++) {
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
    cin >> n >> m >> s >> v;
    for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    for(int i = 1;i <= m;i++) cin >> a[i] >> b[i];

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ll dist = 1ll * (x[i] - a[j]) * (x[i] - a[j]) +
            1ll * (y[i] - b[j]) * (y[i] - b[j]);

            ll move = 1ll * s * v;
            if(move * move >= dist) {
                adj[i + 1].push_back(j + offset + 1);
                adj[j + offset + 1].push_back(i + 1);
                f[i + 1][j + offset + 1] = 1;
            }
        }
    }

    st = 1, en = max(n,m) + offset + 2;
    for(int i = 1;i <= n;i++) {
        adj[st].push_back(i + 1);
        adj[i + 1].push_back(st);
        f[st][i + 1] = 1;
    }

    for(int i = 1;i <= m;i++) {
        adj[i + offset + 1].push_back(en);
        adj[en].push_back(i + offset + 1);
        f[i + offset + 1][en] = 1;
    }

    int max_flow = 0;
    while(1) {
        bfs();
        if(d[en] == oo) break;
        for(int i = 1;i <= en;i++) cur_id[i] = 0;
        while(int delta = dfs(st,oo)) 
            max_flow += delta;
    }
    cout << n - max_flow;

    return 0;
}