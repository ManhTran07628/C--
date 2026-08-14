#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5;
int n,q,type[MM + 5],deg[MM + 5];
ll weight[MM + 5],lazy[MM + 5];
vector<int> adj[MM + 5],heavy[MM + 5];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    int lim = (int) sqrt(2 * n);

    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    
    for(int i = 1;i <= n;i++) {
        if(deg[i] > lim) type[i] = 2;
        else type[i] = 1;

        for(auto v:adj[i]) 
            if(deg[i] > lim || deg[v] > lim)
                heavy[i].push_back(v);
    }

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int u,d; cin >> u >> d;
            // light
            if(type[u] == 1) {
                for(auto v:adj[u])
                    weight[v] += d;
            }
            else lazy[u] += d;
        }
        else {
            int u; cin >> u;
            ll res = weight[u];
            for(auto v:heavy[u]) {
                res += lazy[v];
            }
            cout << res << '\n';
        }
    }
    return 0;
}