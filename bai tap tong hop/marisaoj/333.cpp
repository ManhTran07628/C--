#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int n,q,st[MM],en[MM],Time = 0;
vector<int> adj[MM];
void dfs(int u,int par)
{
    st[u] = ++Time;
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
        }
    }
    en[u] = Time;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    while(q--) {
        int k;
        cin >> k;
        ll x = 0,y = 0,stx = MM,sty = 0;
        for(int i = 1;i <= k;i++) {
            int u;
            cin >> u;
            if(st[u] < stx) {
                x = u;
                stx = st[u];
            }
            if(en[u] > sty) {
                y = u;
                sty = en[u];
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}