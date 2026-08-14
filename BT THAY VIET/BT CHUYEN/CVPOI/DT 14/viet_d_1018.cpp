#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,point[MM],s,p,en[MM],scc[MM],low[MM],num[MM];
int timeDFS = 0,sz = 0,del[MM],Cend[MM];
ll cash[MM];
vector<int> adj[MM],g[MM];
vector<pii> edges;
stack<int> st;

void tarjan(int u)
{
    low[u] = num[u] = ++timeDFS;
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
        sz++;
        do
        {
            v = st.top(); st.pop();
            del[v] = 1;
            scc[v] = sz;
            if(en[v]) Cend[sz] = 1;
        } while(u != v);
    }
}

ll dp[MM],indeg[MM];
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
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }

    for(int i = 1;i <= n;i++) cin >> point[i];
    cin >> s >> p;

    for(int i = 1;i <= p;i++) {
        int a; cin >> a;
        en[a] = 1;
    }

    for(int i = 1;i <= n;i++) {
        if(!num[i])
            tarjan(i);
    }

    for(auto E:edges) {
        int u = E.fi, v = E.se;
        if(scc[u] != scc[v]) {
            g[ scc[u] ].push_back(scc[v]);
            indeg[ scc[v] ]++;
        }
    }

    for(int i = 1;i <= n;i++) cash[ scc[i] ] += point[i];

    kahn(); 

    memset(dp,-1,sizeof(dp));
    dp[ scc[s] ] = cash[ scc[s] ];


    for(auto u:topo) {
        if(dp[u] == -1) continue;
        for(auto v:g[u]) {
            dp[v] = max(dp[v],dp[u] + cash[v]);
        }
    }

    ll res = 0;
    for(int i = 1;i <= sz;i++) {
        if(Cend[i]) res = max(res,dp[i]);
    }
    cout << res;
    return 0;
}