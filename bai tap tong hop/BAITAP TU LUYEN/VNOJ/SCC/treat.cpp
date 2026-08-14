#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,num[MM],low[MM],timeDFS = 0,scc = 0,scc_Node[MM],scc_w[MM],vis[MM];
int Node_w[MM];
vector<int> adj[MM],Nadj[MM];
stack<int> st;
void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int u;
        cin >> u;
        adj[i].push_back(u);
    }
}

void tarjan(int u)
{
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for(auto v:adj[u]) {
        if(scc_Node[v]) continue;
        if(!num[v]) {
            dfs(v);
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
            scc_w[scc]++;
        } while(v != u);
    }
}

void pre_dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(scc_Node[u] != scc_Node[v]) 
            Nadj[scc_Node[u]].push_back(scc_Node[v]);
        if(vis[v]) continue;
        pre_dfs(u);
    }
}

void dfs(int u)
{
    vis[u] = 1;
    Node_w[u]++;
    for(auto v:adj[u]) {

    }
}


void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    for(int i = 1;i <= n;i++) if(!vis[i]) pre_dfs(i);
    memset(vis,0,sizeof(vis));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    return 0;   
}