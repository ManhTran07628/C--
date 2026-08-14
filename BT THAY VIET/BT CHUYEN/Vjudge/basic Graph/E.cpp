#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int start = -1,End = -1;
void dfs(int u)
{
    visited[u] = 1;
    for(auto v:adj[u]) {
        if(start != -1) return;
        if(!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
        else {
            if(parent[u] != v) {
                start = v;
                End = u;
                return;
            }
        }
    }
}
 
void track()
{
    vector<int> cycle;
    cycle.push_back(End);
    int cur = End;
    while(start != cur) {
        cycle.push_back(parent[cur]);
        cur = parent[cur];
    }
    cycle.push_back(End);
    cout << cycle.size() << '\n';
    reverse(cycle.begin(),cycle.end());
    for(auto i:cycle)
        cout << i << ' ';
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            dfs(i);
            if(start != -1) break;
        }
    }
    if(start == -1) cout << "IMPOSSIBLE";
    else {
        track();
    }
    return 0;
}
