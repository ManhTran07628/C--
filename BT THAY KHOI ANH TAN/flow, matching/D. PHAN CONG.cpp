#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 400 + 7;
const int offset = 200;
int n,c[MM][MM],s,t,d[MM],cur_id[MM],f[MM][MM];
vector<int> adj[MM];

void bfs()
{
    fill(d+1,d+t+1,oo);
    d[s] = 0;
    queue<int> q;
    q.push(s);
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
    if(u == t) return cur_delta;

    for(; cur_id[u] < adj[u].size(); cur_id[u]++) {
        int v = adj[u][ cur_id[u] ];

        if(f[u][v] == 0 || d[v] != d[u] + 1) continue;

        int delta = dfs(v, min(cur_delta,f[u][v]));
        if(delta == 0) continue;

        f[u][v] -= delta;
        f[v][u] += delta;
        
        return delta;
    }
    return 0;
}

void build(int lim)
{
    for(int i = 1;i <= t;i++) adj[i].clear();

    for(int i = 1;i <= t;i++)
        for(int j = 1;j <= t;j++) f[i][j] = 0;

    for(int i = 1;i <= n;i++)   
        for(int j = 1;j <= n;j++) {
            if(c[i][j] > lim) continue;
            int a = i, b = j + offset;
            adj[a].push_back(b);
            adj[b].push_back(a);
            f[a][b] = 1;
        }

    for(int i = 1;i <= n;i++) {
        int a = i, b = i + offset;

        f[s][a] = 1;

        adj[s].push_back(a);
        adj[a].push_back(s);

        f[b][t] = 1;

        adj[b].push_back(t);
        adj[t].push_back(b);
    }
}

bool check(int lim)
{
    build(lim);

    int max_flow = 0;

    while(1) {
        bfs();
        if(d[t] == oo) break;
        for(int i = 1;i <= t;i++) cur_id[i] = 0;
        while(int delta = dfs(s,oo)) 
            max_flow += delta;
    }


    return max_flow == n;
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
    cin >> n;
    for(int i = 1;i <= n;i++)   
        for(int j = 1;j <= n;j++) {
            cin >> c[i][j];
        }

    s = n + offset + 1;
    t = s + 1;

    // cout << s << ' ' << t << '\n';


    // cout << check(36);

    // for(int i = 1;i <= t;i++) {
    //     if(adj[i].size() == 0) continue;
    //     // cout << i << ": ";
    //     for(auto v:adj[i]) cout << i << ' ' << v << ' ' << f[i][v] << '\n';
    // }
    int L = 1, R = 1e9, ans = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
        // cout << mid << '\n';
    }

    cout << ans;
    return 0;
}