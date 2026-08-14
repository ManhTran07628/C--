#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 2e5+7;
int n,m,color[MM],parent[MM],ok = 0,s = 0,t = 0;
vector<int> adj[MM],ans;
 
bool dfs(int u)
{
    color[u] = 1;
    for(auto v:adj[u]) {
        if(color[v] == 0) {
            parent[v] = u;
            if(dfs(v)) return 1;
        }
        else if(color[v] == 1) {
            s = u,t = v;
            return 1;
        }
    }
    color[u] = 2;
    return 0;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1;i <= n;i++) {
        if(dfs(i)) {
            ans.push_back(s);
            int res = s;
            while(res != t) {
                if(res == 0) break;
                ans.push_back(parent[res]);
                res = parent[res];
            }
            ans.push_back(s);
            reverse(ans.begin(),ans.end());
 
            cout << ans.size() << '\n';
            for(auto i:ans) cout << i << ' ';
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
