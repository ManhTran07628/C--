#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q;
int num[MM],en[MM],m = 0,h[MM];
vector<int> adj[MM],List[MM];

void dfs(int u,int par)
{
    num[u] = ++m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
    en[u] = ++m;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2;i <= n;i++) {
        int u = i,v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) {
        List[ h[i] ].push_back( num[i] );
    }
    for(int i = 0;i <= n;i++) {
        sort(List[i].begin(),List[i].end());
    }
    cin >> q;
    while(q--) {
        int U,D;
        cin >> U >> D;
        int cnt = upper_bound(List[D].begin(),List[D].end(),en[U]) -
         lower_bound(List[D].begin(),List[D].end(),num[U]);
        cout << cnt << '\n';
    }

    return 0;
}