#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m,c[MM],indeg[MM];

vector<int> adj[MM],g[MM];
vector<pii> edges;

int num[MM],low[MM],del[MM],timeDFS = 0,scc[MM],sz = 0;
ll scc_val[MM];

stack<int> st;

void tarjan(int u)
{
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for(auto v:adj[u]) {
        if(del[v]) continue;
        if(!num[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }

    if(num[u] == low[u]) {
        int v;
        ++sz;
        do 
        {
            v = st.top(); st.pop();
            scc[v] = sz; scc_val[sz] += c[v];
            del[v] = 1;
        } while(v != u);
    }
}

vector<int> topo;
void kahn()
{
    queue<int> q;
    for(int i = 1;i <= sz;i++) {
        if(indeg[i] == 0) {
            topo.push_back(i);
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                topo.push_back(v);
                q.push(v);
            }
        }
    }
}

ll dp[MM];

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
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }

    for(int i = 1;i <= n;i++)
        if(!num[i])
            tarjan(i);

    for(auto E:edges) {
        int u = E.fi, v = E.se;
        if(scc[u] != scc[v]) {
            g[ scc[u] ].push_back( scc[v] );
            indeg[ scc[v] ]++;
        }
    }
    kahn();

    // for(int i = 1;i <= n;i++) cout << i << ' ' << scc[i] << ' ' << scc_val[ scc[i] ] << '\n';

    for(int i = 1;i <= sz;i++) dp[i] = -oo;
    dp[ scc[1] ] = scc_val[ scc[1] ];

    for(auto u:topo) {
        if(dp[u] < 0) continue;

        for(auto v:g[u]) {
            dp[v] = max(dp[v],dp[u] + scc_val[v]);
        }
    }
    
    ll res = 0;
    for(int i = 1;i <= sz;i++) {
        res = max(res,dp[i]);
    }
    cout << res;
    return 0;
}