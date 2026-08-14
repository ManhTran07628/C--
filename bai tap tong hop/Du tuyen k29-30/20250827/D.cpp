#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,a,b,p[MM];
unordered_map<int,int> mp;
vector<int> ans;
void init()
{
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++) {
        cin >> p[i];
        mp[p[i]]++;
    }
}

struct DSU
{
    map<int,int> par,sz;
    void make_sets() 
    {
        for(int i = 1;i <= n;i++) {
            par[p[i]] = p[i];
            par[a-p[i]] = a-p[i];
            par[b-p[i]] = b-p[i];
            sz[i] = 1;
        }
    }

    int find_sets(int u)
    {
        if(u == par[u]) return u;
        return par[u] = find_sets(par[u]);
    }

    void unite(int u,int v)
    {
        u = find_sets(u);
        v = find_sets(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u,v);
        sz[u] += sz[v];
        par[v] = u;
    }
};


DSU g;

bool solve(vector<int> &ans)
{
    g.make_sets();
    for(int i = 1;i <= n;i++) {
        if(!mp[a-p[i]] && !mp[b-p[i]]) return 0;
        if(mp[a-p[i]]) g.unite(p[i],a-p[i]);
        if(mp[b-p[i]]) g.unite(p[i],b-p[i]);
    }
    unordered_map<int,int> color; // 1 - A  2 - B
    for(int i = 1;i <= n;i++) {
        int root = g.find_sets(p[i]);
        int hasA = mp[a-p[i]];
        int hasB = mp[b-p[i]];
        if(!hasA && !hasB) return 0;
        if(!hasA) {
            if(color[root] == 1) return 0;
            color[root] = 2;
        }
        else if(!hasB) {
            if(color[root] == 2) return 0;
            color[root] = 1;
        }
    }

    for(int i = 1;i <= n;i++) {
        int root = g.find_sets(p[i]);
        if(color[root] == 0) color[root] = 1;
    }
    for(int i = 1;i <= n;i++) {
        ans.push_back(color[g.find_sets(p[i])]);
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    // solve();
    if(solve(ans)) {
        cout << "YES" << '\n';
        for(auto i:ans) cout << (i == 1 ? 0 : 1) << ' ';
    }
    else cout << "NO";
    return 0;
}