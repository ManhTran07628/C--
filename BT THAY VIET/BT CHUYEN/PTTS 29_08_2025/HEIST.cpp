#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e5+7;
int n,m,cash[MM],P,S,Exit[MM],exit_node[MM];
int low[MM],num[MM],timeDFS = 0,scc[MM],vis[MM],indeg[MM];
ll ans = 0,dist[MM],ms = 1,cash_scc[MM];
vector<int> adj[MM],Nadj[MM];
stack<int> st;

void init()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1;i <= n;i++) {
        cin >> cash[i];
    }
    cin >> S >> P;
    for(int i = 1;i <= P;i++) {
        int u;
        cin >> u;
        exit_node[u] = 1;
    }
}

void tarjan(int u)
{
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for(auto v:adj[u]) {
        if(scc[v]) continue;
        if(!num[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else {
            low[u] = min(low[u],num[v]);
        }
    }
    if(low[u] == num[u]) {
        int v = -1;
        do
        {
            v = st.top();
            st.pop();
            scc[v] = ms;
            cash_scc[ms] += cash[v];    
            if(exit_node[v]) Exit[ms] = 1;
            
        } while (v != u);
        ms++;
    }
}

void pre_dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(!vis[v]) {
            if(scc[u] != scc[v]) {
                Nadj[scc[u]].push_back(scc[v]);
                indeg[scc[v]]++;
            }
            pre_dfs(v);
        }
    }
}
void Kahn()
{
    vector<int> topo;
    queue<int> q;
    for(int i = 1;i < ms;i++) {
        if(!indeg[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto v:Nadj[u]) {
            if(dist[v] < dist[u] + cash_scc[v]) {
                dist[v] = dist[u] + cash_scc[v];
            }

            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
    // for(auto i:topo) cout << i << ' ';
}


void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    pre_dfs(S);
    
    memset(vis,0,sizeof(vis));

    dist[scc[S]] = cash_scc[scc[S]];
    
    Kahn();

    for(int i = 1;i < ms;i++) if(Exit[i]) ans = max(ans,dist[i]);
    cout << ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}