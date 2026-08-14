#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e3 + 7;
int n,w,a[MM],in[MM],out[MM],m = 0,tour[MM];
int dp[MM][MM],st[MM];
vector<int> adj[MM];


void dfs(int u,int par)
{
    in[u] = ++m;
    tour[m] = u;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        st[u] += st[v];
    }
    st[u] += a[u];
    out[u] = m;
}

struct Trace{int u,w,state;} f[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    cin >> n >> w;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    dfs(1,0);
    dp[1][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int sum = 0;sum <= w;sum++) {
            if(!dp[i][sum]) continue;

            if(!dp[i+1][sum]) {
                dp[i+1][sum] = 1;
                f[i+1][sum] = {i,sum,0};
            }

            int u = tour[i];
            if(sum + st[u] <= w && !dp[ out[u] + 1 ][ sum + st[u] ]) {
                dp[ out[u] + 1 ][ sum + st[u] ] = 1;
                f[ out[u] + 1 ][ sum + st[u] ] = {i,sum,u};
            }
        }
    }

    if(!dp[n + 1][w]) cout << -1;
    else {
        vector<int> trace;
        int cur_i = n + 1, cur_w = w;
        while(cur_i > 1) {
            Trace cur = f[cur_i][cur_w];
            if(cur.state) trace.push_back(cur.state);
            cur_i = cur.u;
            cur_w = cur.w;
        }
        cout << trace.size() << '\n';
        for(auto x:trace) cout << x << ' ';
    }
    return 0;
}