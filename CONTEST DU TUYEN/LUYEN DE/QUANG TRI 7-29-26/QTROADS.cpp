#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m;
vector<pii> adj[MM];
struct Edge{int u,v,w;};
vector<Edge> edges;

namespace subtask1
{
    void solve()
    {
        ll res = 0;
        for(ll i = 1;i <= m;i++) {
            res += 1ll * i * -1 + 1ll * i * i * -1;
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "QTROADS"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    if(m == n - 1) subtask1::solve();
    return 0;
}