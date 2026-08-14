#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n;
vector<int> adj[MM];

void init()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int posA = -1,posB = -1,length = 0;
int h[MM];
void dfs(int u,int par,int &pos)
{

    if(length < h[u]) {
        pos = u;
        length = h[u];
    }
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u,pos);
    }
}

void solve()
{
    dfs(1,0,posA);
    length = 0;
    memset(h,0,sizeof(h));
    dfs(posA,0,posB);
    cout << length;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}