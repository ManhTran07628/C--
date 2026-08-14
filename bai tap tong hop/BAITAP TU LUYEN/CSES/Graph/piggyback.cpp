#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5+7;
vector<int> adj[MM];
int stepA[MM],visited[MM],stepB[MM],stepD[MM];
void bfs(int x,int *step)
{
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                step[v] = step[u] + 1;
                q.push(v);
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "piggyback"
    freopen(taskname ".in","r",stdin);
    freopen(taskname ".out","w",stdout);
    int b,e,p,n,m;
    cin >> b >> e >> p >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1,stepA);
    bfs(2,stepB);
    bfs(n,stepD);
    int totalcost = stepA[n]*b+stepB[n]*e;
    for(int i = 1;i <= n;i++) {
        int cost = stepA[i]*b+stepB[i]*e+stepD[i]*p;
        totalcost = min(cost,totalcost);
    }
    cout << totalcost;
    return 0;
}