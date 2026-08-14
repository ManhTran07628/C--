#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int n,m,ok = 1;
vector<vector<int>> adj(MAXN);
int team[MAXN];
int visited[MAXN];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    team[u] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto x: adj[v]) {
            if(!visited[x]) {
                team[x] = 3-team[v];
                visited[x] = 1;
                q.push(x);
            }
            else {
                if(team[x] == team[v]) ok = 0;
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            bfs(i);
            if(!ok) { 
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        cout << team[i] << ' ';
    }
    return 0;
}