#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
int n,m,timeDFS = 0,num[MM],low[MM],vis[MM];
int bridge = 0,arti = 0;
vector<int> P,Q;
vector<int> adj[MM];
map<pair<int,int>,int> lt;
void dfs(int u,int par)
{
    int childNode = 0,ok = 0;
    low[u] = num[u] = ++timeDFS;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] == num[v]) { // bridge
                P.push_back(lt[{u,v}]);
                bridge++;
            }
            childNode++;
            if(u == par) {
                if(childNode >= 2) {// articulation point
                    ok = 1;
                }
            }
            else if(low[v] >= num[u]) ok = 1;
        }
        else {
            low[u] = min(low[u],num[v]);
        }
    }
    if(ok) Q.push_back(u);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        lt[{u,v}] = i;
        lt[{v,u}] = i;
    }
    for(int i = 1;i <= n;i++) {
        if(!num[i]) dfs(i,i);
    }
    sort(P.begin(),P.end());
    sort(Q.begin(),Q.end());
    cout << bridge << ' ' << Q.size() << '\n';
    for(auto i:P) cout << i << ' ';
    cout << '\n';
    for(auto i:Q) cout << i << ' ';
    return 0;
}