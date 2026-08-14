#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int n,m;
set<int> adj[MM];

void EulerPath(int u)
{
    vector<ll> path;
    stack<ll> st;
    st.push(u);
    while(!st.empty()) {
        ll v = st.top();
        if(adj[v].size() != 0) {
            ll y = *adj[v].begin();
            adj[v].erase(y);
            st.push(y);
        }
        else {
            path.push_back(v);
            st.pop();
        }
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
    }
    EulerPath(1);
    return 0;
}