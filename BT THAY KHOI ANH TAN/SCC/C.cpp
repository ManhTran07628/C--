#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 1e6+7;
int n,m,num[MM],low[MM],timeDFS,scc_Node[MM],scc = 0,scc_sz[MM],vis[MM],outdeg[MM];
vector<int> adj[MM];

void load_graph()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

stack<int> st;
void tarjan(int u)
{
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for(auto v:adj[u]) {
        if(scc_Node[v]) continue;
        if(!num[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }
    
    if(num[u] == low[u]) {
        int v;
        scc++;
        do
        {
            v = st.top(); st.pop();
            scc_Node[v] = scc;
            scc_sz[scc]++;
        } while(v != u);
        
    }
}

void load_new_graph(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(scc_Node[v] != scc_Node[u]) {
            outdeg[scc_Node[u]]++;
        }
        if(!vis[v]) load_new_graph(v);
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    for(int i = 1;i <= n;i++) if(!vis[i]) load_new_graph(i);
    int ans = n;
    for(int i = 1;i <= scc;i++) {
        if(!outdeg[i]) ans = min(ans,scc_sz[i]);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}