#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e4+7;
ll n,m,low[MM],num[MM],deleted[MM],timeDFS = 0,scc = 0;
stack<ll> st;
vector<ll> adj[MM];

void Tarjan(int u)
{
    low[u] = num[u] = ++timeDFS;
    st.push(u);
    for(auto v:adj[u]) {
        if(deleted[v]) continue;
        if(!num[v]) {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }
    if(low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = st.top();
            st.pop();
            deleted[v] = 1;
        }
        while(v != u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i =  1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1;i <= n;i++) {
        if(!num[i]) Tarjan(i);
    }
    cout << scc;
    return 0;
}