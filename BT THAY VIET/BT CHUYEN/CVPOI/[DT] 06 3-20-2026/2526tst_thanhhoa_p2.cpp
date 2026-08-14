#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m,s[MM],x[MM],y[MM];


namespace subtask12
{
    vector<int> v,res;
    int b[MM];
    bool check()
    {
        for(int i = 1;i <= n;i++) b[i] = s[i];
        for(auto ct:v) {
            b[ x[ct] ] ^= 1;
            b[ y[ct] ] ^= 1;
        }

        for(int i = 1;i <= n;i++) if(!b[i]) return 0;
        return 1;
    }

    void Try(int id)
    {
        if(id > m) {
            if(check()) {
                res = v;
            }
            return;
        }
        v.push_back(id);
        Try(id+1);
        v.pop_back();

        Try(id+1);
    }

    void solve()
    {
        if(check()) {
            cout << 0;
            return;
        }
        Try(1);
        if(res.size() == 0) cout << -1;
        else {
            cout << res.size() << '\n';
            for(auto x:res) cout << x << ' ';
        }
    }
}


vector<pair<int,int>> adj[MM];
int c[MM],vis[MM];
vector<int> res;
namespace sol
{
    void dfs(int u,int par)
    {
        vis[u] = 1;
        int type = -1;
        for(auto N:adj[u]) {
            int v = N.fi;
            if(v == par) type = N.se;
            if(vis[v]) continue;
            dfs(v,u);
        }
        if(!s[u]) {
            s[u] ^= 1;
            s[par] ^= 1;
            res.push_back(type);
        }
    }

    void solve()
    {
        dfs(1,0);
        if(!s[1]) cout << -1;
        else {
            cout << res.size() << '\n';
            for(auto f:res) cout << f << ' ';
        }
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> s[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> x[i] >> y[i];
        adj[x[i]].push_back({y[i],i});
        adj[y[i]].push_back({x[i],i});
    }
    sol::solve();
    return 0;
}