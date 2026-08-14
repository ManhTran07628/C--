#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,num[MM],low[MM],timeDFS = 0,scc = 0,scc_Node[MM],vis[MM];
int indeg[MM];
vector<int> adj[MM],Nadj[MM];

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

    if(low[u] == num[u]) {
        int v;
        scc++;
        do 
        {
            v = st.top(); st.pop();
            scc_Node[v] = scc;
        }
        while(v != u);
    }
}

void load_new_graph(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(scc_Node[v] != scc_Node[u]) {
            Nadj[scc_Node[u]].push_back(scc_Node[v]);
            indeg[scc_Node[v]]++;
        }
        if(!vis[v]) load_new_graph(v);
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    for(int i = 1;i <= n;i++) if(!vis[i]) load_new_graph(i);
    int ans = 0;
    for(int i = 1;i <= scc;i++) {
        if(!indeg[i]) ans++;
    }
    cout << ans;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "HELI"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    load_graph();
    solve();
    return 0;
}