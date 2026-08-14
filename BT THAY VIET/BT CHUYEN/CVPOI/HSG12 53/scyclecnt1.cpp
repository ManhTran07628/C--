#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define oo (ll) 1e18
const int MM = 4e5 + 7;
const int MOD = 1e9 + 7;
int n;
vector<pii> edges;

const int MS1 = 17;
namespace subtask1
{
    int adj[MS1][MS1], res = 0;
    vector<int> Node;

    bool check()
    {
        if(Node.empty() || Node.size() <= 2) return 0;
        int st = Node[Node.size() - 1];
        int cur = st;
        for(int i = Node.size() - 2;i >= 0;i--) {
            int nxt = Node[i];
            if(!adj[cur][nxt]) return 0;
            cur = nxt;
        }
        if(adj[cur][st]) return 1;
        return 0;
    }

    void Try(int id)
    {
        if(id == n + 1) {
            // res += check();
            if(check()) {
                res++;
            }
            return;
        }
        Node.push_back(id);
        Try(id + 1);
        Node.pop_back();

        Try(id + 1);
    }

    void solve()
    {
        for(int u = 1;u <= n;u++) {
            int v = (u != n ? u + 1 : 1);
            edges.push_back({u,v});
            // cout << u << ' ' << v << '\n';
        }
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        Try(1);
        cout << res;
    }
}

namespace subtask5
{
    ll dp[MM];
    int id = 0;
    vector<int> adj[MM];
    struct Node{int a,b,c,d;};
    vector<Node> N;
    map<pii,int> mp;
    map<pii,vector<int>> st;

    int vis[MM],del[MM];

    void find_cycle3()
    {
        for(int i = 1;i <= n;i++)
            for(auto j: adj[i]) {
                if(j < i) continue;
                for(auto k:adj[j]) {
                    if(k < j) continue;
                    if(mp[{i,k}]) {
                        // cout << i << ' ' << j << ' ' << k << '\n';
                        N.push_back({i,j,k,++id});
                    }
                }
            }
    }

    void dfs(int u,int par)
    {
        ll cur = 1;
        for(auto v:adj[u]) {
            if(v == par) continue;
            dfs(v,u);
            cur = (cur % MOD * (dp[v] + 1) % MOD) % MOD;
        }
        dp[u] = cur;
    }
    ll res = 0;

    void solve()
    {
        for(int u = 1;u <= n;u++) {
            int v = (u != n ? u + 1 : 1);
            mp[{u,v}] = mp[{v,u}] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // N.push_back({u,u+1,u+2,++id});
        }
        for(auto E:edges) {
            int u = E.fi, v = E.se;
            mp[{u,v}] = mp[{v,u}] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // if(u + 2 == v) {
            //     N.push_back({u,u+1,u+2,++id});
            // }
        }
        for(int i = 1;i <= id;i++) {
            if(!adj[i].size()) continue;
            sort(adj[i].begin(),adj[i].end());
        }
        find_cycle3();

        for(int i = 1;i <= id;i++) {
            if(!adj[i].size()) continue;
            adj[i].clear();
        }

        for(auto E:N) {
            // cout << E.a << ' ' << E.b << ' ' << E.c << ' ' << E.d << '\n';
            st[{E.a,E.b}].push_back(E.d);
            st[{E.a,E.c}].push_back(E.d);
            st[{E.b,E.c}].push_back(E.d);
        }

        for(auto E:st) {
            int u = E.fi.fi, v = E.fi.se;
            vector<int> vec = E.se;
            if(vec.size() == 2) {
                int i = vec[0], j = vec[1];
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        dfs(1,0);
        for(int i = 1;i <= id;i++) {
            res += dp[i]; res %= MOD;
            // cout << i << ' ';
        }
        cout << res;
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
    cin >> n;
    for(int i = 1;i <= n - 3;i++) {
        int u,v; cin >> u >> v;
        if(u > v) swap(u,v);
        edges.push_back({u,v});
    }
    subtask5::solve();
    return 0;
}