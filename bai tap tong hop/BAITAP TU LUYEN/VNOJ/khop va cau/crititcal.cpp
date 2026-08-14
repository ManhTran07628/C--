#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,m,low[MM],num[MM],timeDFS = 0,point[MM],cNode[MM];
int comp[MM],parent[MM];
vector<int> adj[MM];

int find_set(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

void CntComp(int u)
{
    comp[u] = 1;
    for(auto v:adj[u]) {
        if(!parent[v]) {
            parent[v] = u;
            CntComp(v);
            comp[u] += comp[v];
        }
    }
}

void dfs(int u,int par)
{
    vector<int> c;
    int child = 0;
    low[u] = num[u] = ++timeDFS;
    cNode[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            cNode[u] += cNode[v];
            if(low[v] >= num[u]) {
                c.push_back(cNode[v]);
                child += cNode[v];
                // int A = cNode[v];
                // int B = comp[find_set(u)]-A-1;
                // point[u] += A*B;
            }
        }
        else low[u] = min(low[u],num[v]);
    }
    for(int i = 0;i < c.size();i++) {
        for(int j = i+1;j < c.size();j++) {
            point[u] += c[i]*c[j];
        }
    }
    int A = child;
    int B = comp[find_set(u)]-A-1;
    point[u] += A*B;
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
    }
    for(int i = 1;i <= n;i++) {
        if(!comp[i]) {
            parent[i] = i;
            CntComp(i);
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!num[i]) dfs(i,i);
    }
    double ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += point[i];
    }
    cout << fixed << setprecision(9) << ans/n;
    return 0;
}