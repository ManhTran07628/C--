#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,low[MM],num[MM],timeDFS = 0,scc = 0,scc_Node[MM],vis[MM];
int ans = 0,outdeg[MM],indeg[MM];
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
}

void tarjan(int u)
{
    low[u] = num[u] = ++timeDFS;
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
        } while (v != u);
    }
}

void pre_dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(scc_Node[u] != scc_Node[v]) {
            Nadj[scc_Node[u]].push_back(scc_Node[v]);
            indeg[scc_Node[v]]++;
        }
        if(!vis[v]) pre_dfs(v);
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:Nadj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    for(int i = 1;i <= n;i++) if(!vis[i]) pre_dfs(i);

    memset(vis,0,sizeof(vis));

    // for(int i = 1;i <= n;i++) cout << i << ' ' << scc_Node[i] << '\n';
    for(int i = 1;i <= scc;i++) {
        if(!indeg[i]) ans++;
    }

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