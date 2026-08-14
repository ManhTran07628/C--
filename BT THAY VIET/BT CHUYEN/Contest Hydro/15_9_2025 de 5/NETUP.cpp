#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,k;
vector<pair<int,ll>> adj[MM];
struct edge{ll u,v,w;};
vector<edge> edges;
void readinput()
{
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        ll p,w;
        cin >> p >> w;
        adj[i+1].push_back({p,w});
        adj[p].push_back({i+1,w});
        edges.push_back({i+1,p,w});
    }
}

namespace subtask123
{
    ll cost = oo,deg[MM],cnt = 0;
    bool check()
    {
        return n <= 15;
    }


    void solve()
    {
        int m = n-1;
        for(int mask = 0;mask < (1 << m);mask++) {
            memset(deg,0,sizeof(deg));
            bool valid = 1;
            ll total_w = 0;
            for(int i = 0;i < m;i++) {
                if(mask >> i & 1) {
                    ll u = edges[i].u, v = edges[i].v, w = edges[i].w;
                    deg[v]++; deg[u]++; total_w += w;
                }
            }
            for(int i = 1;i <= n;i++) {
                if(deg[i] > k) valid = 0;
            }
            ll t_edges = __builtin_popcount(mask);
            if(valid) {
                if(t_edges > cnt) {
                    cnt = max(cnt,t_edges);
                    cost = total_w;
                }
                else if(t_edges == cnt) cost = min(cost,total_w);
            }
        }
        cout << cnt << ' ' << cost;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask123::solve();
    return 0;
}