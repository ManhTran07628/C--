#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m,k;
vector<int> adj[MM];

namespace subtask1
{
    int d[MM];
    void solve()
    {
        queue<int> q;
        for(int i = 1;i <= n;i++) d[i] = 1e9;
        d[1] = 0;
        q.push(1);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto v:adj[u]) {
                if(d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        for(int i = 2;i <= n;i++) cout << d[i] << ' ' << 1 << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "TELEP"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    subtask1::solve();
    return 0;
}