#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k,res = 0;
int a[MM],dp[MM][2],st[MM];
vector<int> adj[MM];


void dfs(int u,int par)
{
    st[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        st[u] += st[v];
    }
    if(st[u] >= k) {
        res++;
        st[u] = 0;
    }
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
    cin >> n >> k;
    for(int i = 2;i <= n;i++) {
        int u; cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    dfs(1,0);
    cout << res;
    return 0;
}