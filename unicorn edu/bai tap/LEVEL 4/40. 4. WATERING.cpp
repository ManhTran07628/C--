#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e5+7;
int n,comps = 0;
struct edge{int u,v,w;};
vector<edge> edges;

struct DSU
{
    vector<int> par;
    DSU(int n) : par(n + 7) {
        for(int i = 1;i <= n;i++)
            par[i] = i;
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        edges.push_back({0,i,a});
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            int a; cin >> a;
            edges.push_back({i,j,a});
        }

    sort(edges.begin(),edges.end(), [] (edge a,edge b){
        return a.w < b.w;
    });
    for(auto U:edges) {
        int u = U.u, v = U.v, w = U.w;
        if(!g.Unite(u,v)) continue;
        comps += w;
    }
    cout << comps;
    
            
    return 0;
}