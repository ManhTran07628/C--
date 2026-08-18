#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k,c[MM],res[MM];
vector<int> adj[MM];

unordered_map<int,int> S[MM],mp;


void dfs(int u,int par)
{
    S[u][ c[u] ]++; 
    for(auto v:adj[u]) {
        if(v == par) continue;

        dfs(v,u);

        if(S[v].size() > S[u].size()) swap(S[u],S[v]);
        for(auto val:S[v]) {
            int cnt = S[u][val.fi] + val.se;
            S[u][val.fi] = cnt;
        }
    }

    for(auto val:S[u]) {
        if(val.se == k) res[u]++;
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
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << res[i] << ' ';
    return 0;
}
