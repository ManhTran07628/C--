#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,t,m;
vector<int> adj[MM];
int par[MM],path[MM],block[MM][MM],st[MM],Cut[MM][MM];

namespace brute
{
    void dfs(int u)
    {
        st[u] = 1;
        for(auto v:adj[u]) {
            if(v == par[u]) continue;
            par[v] = u;
            dfs(v);
            st[u] += st[v];
        }
    }

    void solve()
    {
        dfs(t);
        vector<int> vec;
        int cur = m;
        while(cur != t) {
            vec.push_back(cur);
            cur = par[cur];
        }

        for(auto e:vec) path[e] = 1;

        int block_move = 0, mouse_move = 0;
        int res = 0;
        cur = m;
        int gf = 3;
        while(1) {
            int max_st = -1, sz = 0;
            for(auto v:adj[cur]) {
                if(v == par[cur] || block[cur][v] || block[v][cur]) continue;
                if(st[v] > sz) {
                    sz = st[v];
                    max_st = v;
                }
            }


            if(max_st != -1) {
                block_move++;
                block[max_st][cur] = block[cur][max_st] = 1;

                max_st = -1, sz = 0;
                for(auto v:adj[cur]) {
                    if(v == par[cur] || block[cur][v] || block[v][cur]) continue;
                    if(st[v] > sz) {
                        sz = st[v];
                        max_st = v;
                    }
                }

                if(max_st == -1) break;
                mouse_move++;
                Cut[cur][max_st] = Cut[max_st][cur] = 1;
                cur = max_st;
            }
            else break;
        }

        cur = par[m];
        while(cur != t) {
            for(auto e:adj[cur]) {
                if(e == par[cur] || path[e]) continue;
                res++;
            }
            cur = par[cur];
        }

        cout << mouse_move + block_move + res;
        
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "MOUSE"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> t >> m;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    brute::solve();
    return 0;
}