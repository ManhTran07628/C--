#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2000 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n,m; cin >> n >> m;
    vector<bitset<2007>> adj;
    adj.resize(n + 3);
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 1;i <= n;i++) adj[i][i] = 1;

    ll res = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(adj[i][j] == 1) continue;
            bitset<2007> a = adj[i] | adj[j];
            res += n - (a.count());  
        }
    }
    cout << res / 6;

    return 0;
}