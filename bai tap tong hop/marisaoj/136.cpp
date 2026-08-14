#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,par[MM],sz[MM],cnt = 0,ans[MM];
vector<int> adj[MM];
map<pair<pair<int,int>,int>,int> lt;

struct Node{
    int u,v,w,id;
};
vector<Node> g,pre_g;

int find_sets(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_sets(par[a]);
}

bool unite(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return 0;
    if(sz[b] > sz[a]) swap(a,b);
    sz[a] += sz[b];
    par[b] = a;
    return 1;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        par[i] = i;
    }
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g.push_back({u,v,w,i-1});
    }
    sort(g.begin(),g.end(), [](Node &a,Node &b){
        return a.w < b.w;
    });
    int i = 0;
    while(i < m) {
        int j = i,w = g[i].w;
        while(j < m && g[j].w == w) j++;
        for(int k = i;k < j;k++) {
            int u = g[k].u, v = g[k].v, weight = g[k].w,id = g[k].id;
            u = find_sets(u);
            v = find_sets(v);
            if(u == v) continue;
            ans[id] = 1;
        }
        for(int k = i;k < j;k++) {
            int u = g[k].u, v = g[k].v, weight = g[k].w,id = g[k].id;
            unite(u,v);
        }
        i = j;
    }
    for(int i = 0;i < m;i++) cout << (ans[i] ? 1 : 0);
    return 0;
}