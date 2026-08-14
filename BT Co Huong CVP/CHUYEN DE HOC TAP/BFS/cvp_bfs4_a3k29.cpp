#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e5 + 7;
int n,k,m,dist[MM];
vector<int> adj[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    fill(dist+1,dist+n+1,oo);
    queue<int> q;
    for(int i = 1;i <= k;i++) {
        int a; cin >> a;
        dist[a] = 0;
        q.push(a);
    }
    cin >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for(int i = 1;i <= n;i++) cout << dist[i] << ' ';
    return 0;
}
