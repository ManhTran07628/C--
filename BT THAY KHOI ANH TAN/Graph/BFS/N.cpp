#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
vector<pair<int,int>> adj[MM];
int visited[MM];
int n,m,k,truck_w = LLONG_MAX,cnt = 0;

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto [v,w]:adj[u]) {
            if(!visited[v] && w >= truck_w) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) {
        int p; cin >> p;
        truck_w = min(truck_w,p);
    }
    for(int i = 1;i <= m;i++) {
        int a,b,t;
        cin >> a >> b >> t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            cnt++;
            bfs(i);
        }
    }
    cout << cnt;
    return 0;
}