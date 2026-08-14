#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e4 + 7;
int n,m,k,indeg[MM];
vector<pii> adj[MM];

vector<ll> topo;

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
            if(indeg[v] == 0) {
                topo.push_back(v);
                q.push(v);
            }
        }
    }
}

priority_queue<ll> q[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        indeg[v]++;
    }
    Kahn();
    
    q[n].push(0);

    for(auto u:topo) {
        if(q[u].empty()) continue;
        for(auto N:adj[u]) {
            int v = N.fi, w = N.se;

            int sz = q[u].size();
            priority_queue<ll> cur = q[u];
            while(!cur.empty()) {
                ll new_d = cur.top() + w;
                q[v].push(new_d);
                cur.pop();
            }

            while(q[v].size() > k) q[v].pop();
        }
    }    

    vector<ll> res;
    while(!q[1].empty()) {
        res.push_back(q[1].top());
        q[1].pop();
    }
    sort(res.begin(),res.end());
    for(auto e:res) cout << e << '\n';
    for(int i = 1;i <= k - res.size();i++) cout << -1 << '\n';
    return 0;
}