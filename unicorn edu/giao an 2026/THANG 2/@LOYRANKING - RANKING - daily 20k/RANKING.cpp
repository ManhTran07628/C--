#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector <int> g[N];
int a[N][N], n, m, vis[N];
void bfs(int u, int v)
{
    a[u][v] = 1;
    vis[v] = 1;
    for (auto x : g[v])
        if (!vis[x]) bfs(u, x);
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        a[u][v] = 1;
    }
    for (int i=1; i<=n; i++){
        memset(vis, 0, sizeof(vis));
        bfs(i,i);
    }
    int ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
            if (!a[i][j] && !a[j][i])
             ans ++;
    cout << ans;
    return 0;
}