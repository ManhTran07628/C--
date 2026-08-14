#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,m;
struct Edge{int u,v,w;};
vector<Edge> edges;

struct DSU
{
    vector<int> par;
    DSU(int n) : par(n + 7) {
        for(int i = 1;i <= n;i++) {
            par[i] = i;
        }
    };

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    bool Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        par[b] = a;
        return 1;
    }
} g(MM);

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(), [] (Edge a,Edge b){
        return a.w > b.w;
    });
    int res = 0;
    for(auto U:edges) {
        int u = U.u, v = U.v, w = U.w;
        if(!g.Unite(u,v)) continue;
        res += w;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(g.par[i] == i) cnt++;
    }
    cout << (cnt == 1 ? res : -1);
    return 0;
}