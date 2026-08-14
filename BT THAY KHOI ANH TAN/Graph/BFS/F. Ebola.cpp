#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5+7;
vector<int> adj[MM],aff;
int visited[MM],cnt = 0;
void dfs(int u)
{
    visited[u] = 1;
    for(auto v:adj[u]) {
        if(!visited[v]) {
            aff.push_back(v);
            cnt++;
            dfs(v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        int m,x;
        cin >> m;
        while(m--) {
            cin >> x;
            adj[i].push_back(x);
        }
    }
    aff.push_back(k);
    dfs(k);
    sort(aff.begin(),aff.end());
    cout << aff.size() << '\n';
    for(auto i:aff) cout << i << ' ';
    return 0;
}