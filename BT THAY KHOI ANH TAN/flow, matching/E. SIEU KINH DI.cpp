#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 19
const int MM = 1e3 + 7;
const int offset = 500;
int row,col,s,t,c[MM][MM],d[MM],cur_id[MM];
vector<int> adj[MM];

void bfs()
{
    queue<int> q;
    fill(d+1,d+t+1,oo);
    d[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(d[v] != oo || c[u][v] == 0) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int dfs(int u,int cur_delta)
{
    if(cur_delta == 0) return 0;
    if(u == t) return cur_delta;
    for(; cur_id[u] < adj[u].size(); cur_id[u]++) {
        int v = adj[u][ cur_id[u] ];
        if(d[v] != d[u] + 1 || c[u][v] == 0) continue;

        int delta = dfs(v, min(cur_delta,c[u][v]));
        if(delta == 0) continue;

        c[u][v] -= delta;
        c[v][u] += delta;
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
    cin >> row >> col;
    for(int i = 1;i <= row;i++)
        for(int j = 1;j <= col;j++) {
            char mat; cin >> mat;
            if(mat == '.') {
                int a = i, b = j + offset;
                adj[a].push_back(b);
                adj[b].push_back(a);
                c[a][b] = 1;
            }
        }
    s = max(row,col) + offset + 1;
    t = s + 1;
    for(int i = 1;i <= row;i++) {
        int a = s, b = i;
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] = 1;
    }
    for(int j = 1;j <= col;j++) {
        int a = j + offset, b = t;
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] = 1;
    }

    int max_flow = 0;
    while(1) {
        bfs();
        if(d[t] == oo) break;
        for(int i = 1;i <= t;i++) cur_id[i] = 0;
        while(int delta = dfs(s,oo))
            max_flow += delta;
    }
    cout << max_flow;
    return 0;
}