#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll> 
const int MM = 1e5 + 7;
int n,m,s,t;
ll d[MM];
vector<pii> adj[MM];
vector<int> topo;
int indeg[MM];

void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(indeg[i] == 0) {
            topo.push_back(i);
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto N:adj[u]) {
            int v = N.fi;
            indeg[v]--;
            if(indeg[v] == 0)  {
                q.push(v);
                topo.push_back(v);
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
        adj[u].push_back({v,w});
        indeg[v]++;
    }
    cin >> s >> t;
    for(int i = 1;i <= n;i++) d[i] = -oo;
    d[s] = 0;
    Kahn();
    for(auto u:topo) {
        if(d[u] == -oo) continue;
        for(auto N:adj[u]) {
            ll v = N.fi, w = N.se;
            if(d[v] < d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
    if(d[t] == -oo) cout << "NO PATH";
    else cout << d[t];
    // cout << (d[t] == -oo ? 0 : d[t]);


    return 0;
}