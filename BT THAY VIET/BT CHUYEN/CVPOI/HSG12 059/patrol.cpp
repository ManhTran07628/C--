#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;
multiset<int> adj[MM],Nadj[MM];

vector<int> path;
void solve()
{
    stack<int> st;
    st.push(1);
    while(!st.empty()) {
        int x = st.top();
        if(adj[x].size() > 0) {
            int u = *adj[x].begin();
            adj[x].erase(adj[x].find(u));
            adj[u].erase(adj[u].find(x));
            st.push(u);
        }
        else {
            path.push_back(x);
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
        adj[u].insert(v);
        adj[v].insert(u);
        adj[v].insert(u);
    }
    solve();
    for(auto e:path) cout << e << '\n';
    return 0;
}