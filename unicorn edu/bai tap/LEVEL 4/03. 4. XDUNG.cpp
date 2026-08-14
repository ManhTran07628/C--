#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n;
pii a[MM];
struct Edge{int u,v; ll w;};
vector<Edge> edges;

namespace subtask1
{

    int par[MM];

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

    void solve()
    {
        for(int i = 1;i <= n;i++) 
            par[i] = i;

        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j <= n;j++) {
                int w = min( abs(a[i].fi - a[j].fi), abs(a[i].se - a[j].se) );
                edges.push_back({i,j,w});
            }
        }

        sort(edges.begin(),edges.end(), [] (Edge a, Edge b){
            return a.w < b.w;
        });
        ll res = 0;
        for(auto U: edges) {
            int u = U.u, v = U.v; ll w = U.w;
            if(!Unite(u,v)) continue;
            res += w;
        }
        cout << res;

    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "XDUNG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    subtask1::solve();
    return 0;
}