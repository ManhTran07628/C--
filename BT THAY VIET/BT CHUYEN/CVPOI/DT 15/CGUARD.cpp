#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 500 + 7;
int n,m;
struct Edge{ll u,v,w;};
vector<Edge> edges;

namespace subtask3
{
    ll d[501][501],in_deg[501][501];
    void solve()
    {
        for(int i = 1;i <= n;i++)  
            for(int j = 1;j <= n;j++) {
                d[i][j] = oo;
                if(i == j) d[i][j] = 0;
            }


        for(auto E:edges) {
            int u = E.u, v = E.v, w = E.w;
            d[u][v] = w;
            d[v][u] = w;
        }

        for(int k = 1;k <= n;k++)
            for(int i = 1;i <= n;i++)  
                for(int j = 1;j <= n;j++) {
                    if(d[i][k] == oo || d[k][j] == oo) continue;
                    if(d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }

        for(int i = 1;i <= n;i++) {
            for(auto E:edges) {
                int u = E.u, v = E.v, w = E.w;
                if(d[i][u] + w == d[i][v]) 
                    in_deg[i][v]++;
                if(d[i][v] + w == d[i][u]) 
                    in_deg[i][u]++;
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) {
                ll cnt = 0;
                for(int k = 1;k <= n;k++) {
                    if(d[i][k] + d[k][j] == d[i][j])
                        cnt += in_deg[i][k];
                }
                // cout << in_deg[i][j] << ' ';
                cout << cnt << ' ';
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
        ll u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    subtask3::solve();
    return 0;
}