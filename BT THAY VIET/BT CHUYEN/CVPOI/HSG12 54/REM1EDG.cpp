#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 300 + 7;
int n,a[MM][MM],indeg[MM],del[MM][MM];
ll d[MM][MM],f[MM],SP[MM];
vector<int> adj[MM],Nadj[MM];
struct Edge{int u,v,w;};
vector<Edge> edges;


void bfs(int E_u,int E_v,ll dist[]) 
{
    queue<int> q;
    q.push(1);
    for(int i = 1;i <= n;i++) dist[i] = 1e9;
    dist[1] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(E_u == u && E_v == v) continue;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
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
    cin >> n;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) d[i][j] = oo;
            else d[i][j] = a[i][j];


            if(a[i][j] != -1 && i != j) edges.push_back({i,j,a[i][j]});
        }

    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++) {
                if(d[i][j] > d[i][k] + d[k][j]) 
                    d[i][j] = d[i][k] + d[k][j];
            }

    for(auto E:edges) {
        int u = E.u, v = E.v, w = E.w;
        if(d[1][u] + w == d[1][v]) {
            adj[u].push_back(v);
            indeg[v]++;
            // cout << E.u << ' ' << E.v << ' ' << E.w << '\n';
        }
    }

    bfs(0,0,SP);

    int res = 0;
    for(auto E:edges) {
        int u = E.u, v = E.v, w = E.w;
        if(indeg[v] != 1) continue;
        del[u][v] = 1;

        bfs(u,v,f);
        int cnt = 0;
        for(int i = 1;i <= n;i++)
            if(SP[i] != f[i])
                cnt++;
        
        res = max(res,cnt);
        // cout << cnt << '\n';
    }
    cout << res;
    
    return 0;
}
