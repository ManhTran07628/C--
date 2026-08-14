#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e4+7;
int n,m,a[MM],sz[MM],ans[MM];
vector<int> adj[MM];
set<pair<int,int>> st[MM];
map<int,int> cnt[MM];
// .fi la chi so .se la color

void dfs_size(int u)
{
    sz[u] = 1;
    for(auto v:adj[u]) {
        if(!sz[v]) {
            dfs_size(v);
            sz[u] += sz[v];
        }
    }
}

void dfs(int u,int p)
{
    cnt[u][a[u]]++;
    st[u].insert({1,a[u]});
    for(auto v:adj[u]) {
        if(v != p) {
            dfs(v,u);
            if(st[u].size() < st[v].size()) {
                swap(st[u],st[v]);
                swap(cnt[u],cnt[v]);
            }
            for(auto i:st[v]) {
                int color = i.se, freq = i.fi;
                if(cnt[u][color] > 0) {
                    st[u].erase({cnt[u][color],color});
                    st[u].insert({cnt[u][color]+freq,color});
                }
                else st[u].insert({freq,color});
                cnt[u][color] += freq;
            }
        }
    }
    auto k = *st[u].rbegin();
    if(k.fi > sz[u] / 2) ans[u] = k.se;
    else ans[u] = -1;
}




signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_size(1);
    dfs(1,0);
     while(m--) {
        int u;
        cin >> u;
        cout << ans[u] << '\n';
    }
    return 0;
}