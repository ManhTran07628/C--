#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m,a[MM],s,vis[MM],vis_edge[MM];
vector<pii> adj[MM];
ll energy = 0;

void bfs()
{
    energy += a[s];
    vis[s] = 1;
    while(1) {
        bool ok = 1;
        for(int u = 1;u <= n;u++) {
            for(auto N:adj[u]) {
                int v = N.fi, w = N.se;
                if(!vis[v] && !vis[u]) continue;
                if(energy >= w) {
                    if(!vis[v]) {
                        vis[v] = 1;
                        energy += a[v];
                        ok = 0;
                    }
                    if(!vis[u]) {
                        vis[u] = 1;
                        energy += a[u];
                        ok = 0;
                    }
                }
            }
        }
        if(ok) break;
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
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    bfs();
    cout << energy;
    return 0;
}
