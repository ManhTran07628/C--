#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,double>
const int MM = 1e3 + 7;
int n,m,x[MM],y[MM],par[MM];
struct Edge{int u,v; double w;};
vector<Edge> edges;

int find_set(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_set(par[a]);
}

bool Unite(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b) return 0;
    par[b] = a;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "XD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) par[i] = i;
    for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        Unite(u,v);
    }
    
    for(int u = 1;u <= n;u++) {
        for(int v = 1;v <= n;v++) {
            double X = x[u] - x[v];
            double Y = y[u] - y[v];
            double C = sqrt( X * X + Y * Y );
            edges.push_back({u,v,C});
        }
    }

    sort(edges.begin(),edges.end(),[] (Edge &a, Edge &b){
        return a.w < b.w;
    });
    double cost = 0.0;
    for(auto U:edges) {
        int u = U.u, v = U.v; double w = U.w;
        if(!Unite(u,v)) continue;
        cost += w;
    }
    cout << fixed << setprecision(3) << cost;

    return 0;
}