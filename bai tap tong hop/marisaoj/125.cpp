#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,k,a[MM];
int timeM[MM],timeD[MM]; 
vector<int> adj[MM];

// timeM : time cua marisa
// timeD : time cua bup be

void bfs(int x,int *time)
{
    for(int i = 1;i <= n;i++) time[i] = oo;
    time[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(time[v] > time[u] + 1) {
                time[v] = time[u] + 1;
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
    int ans = 0;
    for(int i = 1;i <= k;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(n,timeD);
    bfs(1,timeM);
    for(int i = 1;i <= k;i++) {
        if(timeD[a[i]] <= timeM[n]) ans++;
    }
    cout << ans;
    return 0;
}