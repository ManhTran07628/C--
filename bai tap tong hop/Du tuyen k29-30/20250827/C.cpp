#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 1e6+7;
int n,par[MM],sz[MM],ans = 0;
pair<int,int> coord[MM];

struct Edge
{
    int u,v,w;
};
vector<Edge> adj;

int find_sets(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_sets(par[a]);
}

bool unite(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return 1;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "moocast"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> coord[i].fi >> coord[i].se;
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            ll x = coord[i].fi - coord[j].fi;
            ll y = coord[i].se - coord[j].se;
            ll dist = x*x+y*y;
            adj.push_back({i,j,dist});
        }
    }
    sort(adj.begin(),adj.end(), [] (Edge &a,Edge &b){
        return a.w < b.w;
    });
    for(auto E:adj) {
        int u = E.u, v = E.v, w = E.w;
        if(!unite(u,v)) continue;
        ans = max(ans,w);
    }
    cout << ans;
    return 0;
}