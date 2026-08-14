#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 2e9
#define pii pair<int,int>
const int MM = 5e3 + 7;
int n,m,k,d[MM][MM][2],deg[MM];
vector<int> adj[MM];

void bfs(int s)
{
    queue<pii> q;
    q.push({s,0});
    for(int i = 1;i <= n;i++) d[s][i][0] = d[s][i][1] = oo;
    d[s][s][0] = 0;
    while(!q.empty()) {
        pii N = q.front(); q.pop();
        int u = N.fi, type = N.se;
        for(auto v:adj[u]) {
            if(d[s][v][type ^ 1] == oo) {
                d[s][v][type ^ 1] = d[s][u][type] + 1;
                q.push({v,type ^ 1});
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
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    for(int i = 1;i <= n;i++) bfs(i);

    while(k--) {
        int s,t,D; cin >> s >> t >> D;
        if(s == t && deg[s] == 0) {cout << "NO" << '\n'; continue;}
        if(d[s][t][D % 2] <= D) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}