#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,q;
int par[MM],sz[MM],vis[MM],ans[MM];
struct dl
{
    int k,v,id;
};
vector<dl> query;

struct Edge {
    int u,v,w;
};
vector<Edge> adj;
void make_sets()
{
    for(int i = 1;i <= n;i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_sets(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_sets(par[a]);
}

void unite(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return;
    if(sz[b] > sz[a]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "mootube"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj.push_back({u,v,w});
    }
    make_sets();
    for(int i = 1;i <= q;i++) {
        int u,v;
        cin >> u >> v;
        query.push_back({u,v,i});
    }
    sort(adj.begin(),adj.end(), [] (Edge &a,Edge &b){
        return a.w > b.w;
    });
    sort(query.begin(),query.end(), [] (dl &a,dl &b){
        return a.k > b.k;
    });
    int i = 0;
    for(auto x:query) {
        int k = x.k, root = x.v, id = x.id;
        while(i < n-1 && adj[i].w >= k) {
            unite(adj[i].u,adj[i].v);
            i++;
        }
        ans[id] = sz[find_sets(root)];
    }
    for(int i = 1;i <= q;i++) cout << ans[i]-1 << '\n';
    return 0;
}