#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,m,deg[MM],vis[MM];
multiset<int> adj[MM];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

vector<int> path;
void euler_cycle(int u)
{
    stack<int> st;
    st.push(u);
    while(!st.empty()) {
        int v = st.top(); 
        if(adj[v].size() > 0) {
            int x = *adj[v].begin();
            st.push(x);
            adj[x].erase( adj[x].find(u) );
            adj[u].erase( adj[u].find(x) );
        }
        else {
            path.push_back(v);
            st.pop();
        }
    }

    reverse(path.begin(),path.end());
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
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++; deg[v]++;
    }
    dfs(1);
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            cout << "NO";
            return 0;
        }
    }
    int ok = 0;
    for(int i = 1;i <= n;i++) {
        if(deg[i] % 2 == 1) ok++;
    }
    if(ok == 0 || ok == 2) {
        cout << "YES";
        euler_cycle(5);
        for(auto e:path) cout << e << ' ';
    }
    else cout << "NO";

    return 0;

}