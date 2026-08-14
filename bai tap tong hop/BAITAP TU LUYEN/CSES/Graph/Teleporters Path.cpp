#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,m,deg_in[MM],deg_out[MM]; 
set<ll> adj[MM];

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
    // if(path.size() != m+1)
    // {
    //     cout << "IMPOSSIBLE";
    //     return;
    // }
    reverse(path.begin(),path.end());
    for(auto x:path) cout << x << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll u,v;
        cin >> u >> v;
        adj[u].insert(v);
        deg_out[u]++; deg_in[v]++;
    }
    int ok = 1;
    for(int i = 2;i < n;i++) {
        if(deg_in[i] != deg_out[i]) ok = 0;
    }
    if(deg_out[1] - deg_in[1] == 1 && deg_in[n] - deg_out[n] == 1) ok = ok;
    else ok = 0;
    if(!ok) cout << "IMPOSSIBLE";
    else {
        EulerPath(1);
    }
    // cout << s << ' ' << t;
    return 0;
}