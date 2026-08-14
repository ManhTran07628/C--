#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,deg[MM];
set<int> adj[MM];

void dfs(int u)
{
    stack<int> st;
    vector<int> path;
    st.push(u);
    while(!st.empty()) {
        int x = st.top();
        if(adj[x].size() != 0) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else {
            path.push_back(x);
            st.pop();
        }
    }
    if(path.size() != m+1) {
        cout << "IMPOSSIBLE";
        return;
    }
    reverse(path.begin(),path.end());
    for(auto x:path) cout << x << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++; deg[v]++;
    }
    int ok = 1;
    for(int i = 1;i <= n;i++) {
        if(deg[i] % 2) ok = 0;
    }
    if(!ok) cout << "IMPOSSIBLE";
    else {
        dfs(1);
    }
    return 0;   
}