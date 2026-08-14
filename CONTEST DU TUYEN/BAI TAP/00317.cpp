#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,color[MM],h[MM],r1 = 0,r2 = 0;
vector<int> adj[MM];

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}

void dfs1(int u,int par,int &cur_res)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(color[u] == 0 && color[v] == 1) {
            // cout << u << ' ' << v << ' ' << h[u] << '\n';
            cur_res++;
        }
        dfs1(v,u,cur_res);
    }
}

// 0 - A   1 - B

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    vector<int> re1,re2;
    for(int i = 1;i <= n;i++) {
        if(h[i] % 2 == 0) {
            re1.push_back(i);
            color[i] = 0;
        }
        else color[i] = 1;
    }

    // for(int i = 1;i <= n;i++) cout << 


    dfs1(1,0,r1);
    for(int i = 1;i <= n;i++) {
        // cout << i << ' ' << h[i] << '\n';
        if(h[i] % 2 == 1) {
            re2.push_back(i);
            color[i] = 0;
        }
        else color[i] = 1;
    }
    dfs1(1,0,r2);
    if(r1 < r2) {
        swap(re1,re2);
        swap(r1,r2);
    }
    cout << r1 << ' ' << re1.size() << '\n';
    for(auto e:re1) cout << e << ' ';
    return 0;
}