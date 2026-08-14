#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int MOD = 1e9+7;
int n,m,low[MM],num[MM],timeDFS = 0,scc = 0,scc_Node[MM],vis[MM];
ll c[MM],min_cost[MM],ans = 1,mncost = 0;
map<int,int> mp;
vector<int> adj[MM],Nadj[MM];

void load_graph()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> c[i];
    cin >> m;
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
        else low[u] = min(low[u],low[v]);
    }

    if(low[u] == num[u]) {
        int v;
        scc++;
        do
        {
            v = st.top(); st.pop();
            scc_Node[v] = scc;
        } while(v != u);
    }
}

void load_new_graph(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(scc_Node[v] != scc_Node[u])
            Nadj[scc_Node[u]].push_back(scc_Node[v]);

        if(!vis[v]) load_new_graph(v);
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) tarjan(i);
    for(int i = 1;i <= n;i++) if(!vis[i]) load_new_graph(i);
    memset(vis,0,sizeof(vis));
    fill(min_cost+1,min_cost+n+1,oo);
    for(int i = 1;i <= n;i++) {
        min_cost[scc_Node[i]] = min(min_cost[scc_Node[i]],c[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(c[i] == min_cost[scc_Node[i]])
            mp[scc_Node[i]]++;
    }
    // for(int i = 1;i <= n;i++) cout << i << ' ' << scc_Node[i] << '\n';
    for(auto v:mp) {
        mncost += min_cost[v.fi];
        ans = (ans * v.se) % MOD;
    }
    cout << mncost << ' ' << ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    load_graph();
    solve();
    return 0;
}