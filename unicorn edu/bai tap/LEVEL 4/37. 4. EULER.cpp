#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,m;
multiset<int> adj[MM];

void eulercycle()
{
    stack<int> st;
    vector<int> path;
    st.push(1);
    while(!st.empty()) {
        int x = st.top();
        if(adj[x].size() > 0) {
            int u = *adj[x].begin();
            // path.push_back(u);
            st.push(u);
            adj[x].erase( adj[x].find( u ) );
            adj[u].erase( adj[u].find( x ) );
        }
        else {
            path.push_back(x);
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
    eulercycle();
    return 0;
}