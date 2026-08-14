#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,low[MM],num[MM],timeDFS = 0,scc = 0,scc_Node[MM],scc_sz[MM];
ll curscc_sz = 0,ans = 0;
vector<int> adj[MM];
vector<pair<int,int>> edges;

void load_graph()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }
}

stack<int> st;

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

    if(low[u] == num[u]) {
        int v;
        scc++;
        do 
        {
            v = st.top(); st.pop();
            scc_Node[v] = scc;
            scc_sz[scc]++;
        }
        while(v != u);
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    sort(edges.begin(),edges.end()); 
    edges.erase(unique(edges.begin(),edges.end()),edges.end());

    for(auto E:edges) {
        int u = E.fi, v = E.se;
        if(scc_Node[u] == scc_Node[v] && u != v) curscc_sz++;
    }
    
    for(int i = 1;i <= scc;i++) {
        ans += scc_sz[i]*(scc_sz[i]-1);
    }
    cout << ans-curscc_sz;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}