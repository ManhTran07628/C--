#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,m,a[MM],indeg[MM];
vector<int> adj[MM];


struct DSU
{
    int par[MM] = {};

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return find_sets(par[a]);
    }

    void Unite(int a,int parent)
    {
        a = find_sets(a);
        parent = find_sets(parent);
        if(a == parent) return;
        par[a] = parent;
    }
} g;

vector<int> topo;

void kahn()
{
    priority_queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.top(); q.pop();
        topo.push_back(u);
        for(auto v:adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                // cout << v << ' ';
                q.push(v);
            }
        }
        // cout << '\n';
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
    for(int i = 1;i <= n;i++) {
        int sz; cin >> sz;
        for(int j = 1;j <= sz;j++) cin >> a[j];

        if(!g.par[ a[sz] ]) g.par[ a[sz] ] = a[sz];

        bool ok = 1;

        for(int j = 2;j <= sz;j++) {
            if(!g.par[ a[j - 1] ] ) {
                g.par[ a[j - 1] ] = a[j];
            }
            else if(g.par[ a[j - 1] ]) {
                int u = g.find_sets( a[j] );
                int v = g.find_sets( a[j - 1] );
                if(u == v) {
                    ok = 0;
                    break;
                }
                else {
                    g.par[ a[j - 1] ] = a[j];
                }
            }

            if(!ok) break;
        }

        if(!ok) break;
    }

    for(int i = 1;i <= n;i++) {
        adj[ g.par[i] ].push_back(i);
    }
    for(int i = 1;i <= n;i++) {
        // cout << i << " : ";
        for(auto j:adj[i]) {
            if(i == j) continue;
            // cout << j << ' ';
            indeg[j]++;
        }
        // cout << '\n';
    }

    kahn();
    reverse(topo.begin(),topo.end());
    for(auto u:topo) cout << u << ' ';

    return 0;   
}