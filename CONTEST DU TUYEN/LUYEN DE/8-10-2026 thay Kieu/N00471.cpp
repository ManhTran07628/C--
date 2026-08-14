#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
const int MOD = 1e9 + 7;
int n,m,s,t,c[MM];
vector<int> adj[MM];
set<int> g[MM];
vector<pii> edges;

int num[MM],low[MM],scc[MM],del[MM],sz = 0,timeDFS = 0;
int indeg[MM];
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
            scc[v] = sz;
            scc_val[sz] += c[v];
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

ll dp[MM],cnt[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }

    for(int i = 1;i <= n;i++) {
        if(!num[i])
            tarjan(i);
    }
    // tarjan(s);
    //   cout << '\n';

    for(auto E:edges) {
        int u = E.fi, v = E.se;
        if(scc[u] != scc[v] && g[ scc[u] ].find( scc[v] ) == g[ scc[u] ].end()) {
            g[ scc[u] ].insert( scc[v] );
            indeg[ scc[v] ]++;
        }
    }

    // for(int i = 1;i <= n;i++) cout << i << ' ' << scc[i] << ' ' << scc_val[ scc[i] ] << '\n';

    kahn();
    for(int i = 1;i <= sz;i++) {
        dp[i] = -oo;

        // cout << i << ": ";
        // for(auto j:g[i]) {
        //     cout << j << ' ';
        // }
        // cout << '\n';

    }
    dp[ scc[s] ] = scc_val[ scc[s] ];
    cnt[ scc[s] ] = 1;

    for(auto u:topo) {

        // cout << u << ' ';

        if(dp[u] == -oo) continue;

        for(auto v:g[u]) {

            // cout << u << "->" << v << '\n';

            if(dp[v] == dp[u] + scc_val[v]) {
                cnt[v] += cnt[u];
                cnt[v] %= MOD;
            }

            if(dp[v] < dp[u] + scc_val[v]) {
                dp[v] = dp[u] + scc_val[v];
                cnt[v] = cnt[u];
                cnt[v] %= MOD;
            }
        }

        // dp[u] += scc_val[u];
    }

    // for(int i = 1;i <= sz;i++) cout << dp[i] << '\n';

    if(dp[ scc[t] ] == -oo) cout << -1 << ' ' << 0;
    else cout << dp[ scc[t] ] << ' ' << cnt[ scc[t] ];

    return 0;
}
