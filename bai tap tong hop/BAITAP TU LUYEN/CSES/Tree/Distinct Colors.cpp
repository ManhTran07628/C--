#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 2e5+7;
int n,color[MM],ans[MM];
vector<int> adj[MM];
map<int,int> lt[MM];

void dfs(int u,int par)
{
    lt[u][color[u]]++;
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
            if(lt[v].size() > lt[u].size()) swap(lt[u],lt[v]);
            for(auto v:lt[v]) {
                lt[u][v.first]++;
            }
        }
    }
    ans[u] = lt[u].size();
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) 
        cin >> color[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) 
        cout << ans[i] << ' ';
    return 0;
}