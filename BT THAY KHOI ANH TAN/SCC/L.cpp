#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m,k[MM],indeg[MM],num[MM],low[MM],timeDFS = 0,scc[MM],del[MM],sz = 0;
ll scc_val[MM],dp[MM];
vector<int> adj[MM],Nadj[MM];
vector<pii> edges;
stack<int> st;

void tarjan(int u)
{
    st.push(u);
    num[u] = low[u] = ++timeDFS;
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
        sz++;
        do
        {
            v = st.top(); st.pop();
            scc[v] = sz; scc_val[sz] += k[v];
            del[v] = 1;
        } while(u != v);
    }
}   

vector<int> topo;

void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= sz;i++) {
        if(!indeg[i]) {
            q.push(i);
            topo.push_back(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:Nadj[u]) {
            indeg[v]--;
            if(!indeg[v]) {
                topo.push_back(v);
                q.push(v);
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
    for(int i = 1;i <= n;i++) cin >> k[i];
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }
    for(int i = 1;i <= n;i++) {
        if(!num[i]) tarjan(i);
    }
    for(auto E:edges) {
        int u = E.fi, v = E.se;
        int x = scc[u], y = scc[v];
        if(x != y) {
            indeg[y]++;
            Nadj[x].push_back(y);
        }
    }
    // for(int i = 1;i <= n;i++) cout << i << ' ' << num[i] << ' ' << low[i] << '\n';
    // for(int i = 1;i <= n;i++) cout << i << ' ' << scc[i] << ' ' << scc_val[ scc[i] ] << '\n';
    Kahn();
    ll res = 0;
    for(auto u:topo) dp[u] = scc_val[u];
    for(auto u:topo) {
        for(auto v:Nadj[u]) {
            dp[v] = max(dp[v],dp[u] + scc_val[v]);
        }
    }

    for(auto u:topo) res = max(res,dp[u]);
    cout << res;
    return 0;
}