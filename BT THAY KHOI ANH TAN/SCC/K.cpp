#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;
int dp[MM],in[MM];
vector<int> adj[MM],topo;


void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(in[i] == 0) {
            q.push(i);
            topo.push_back(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            in[v]--;
            if(in[v] == 0) {
                q.push(v);
                topo.push_back(v);
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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    Kahn();
    for(int u:topo) {
        for(auto v:adj[u]) {
            dp[v] = max(dp[v],dp[u] + 1);
        }
    }

    int res = 0;
    for(auto u:topo) res = max(res,dp[u]);
    cout << res;

    return 0;
}