#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 2e5 + 7;
int n,m;
set<int> g[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "newedges"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        if(u > v) swap(u,v);
        g[u].insert(v);
    }

    ll res = 0;
    for(int i = 1;i <= n;i++) {
        if(g[i].empty()) continue;
        res += g[i].size(); 

        int v1 = *g[i].begin();
        g[i].erase(g[i].begin());

        if(g[i].size() > g[v1].size()) {
            swap(g[i],g[v1]);
        }
        for(auto u:g[i]) {
            g[v1].insert(u);
        }
    }
    cout << res - m;
    return 0;
}