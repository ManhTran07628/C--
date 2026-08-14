#include<bits/stdc++.h>
using namespace std;
long long d;
const int N = 1e5+10;
vector <int> g[N];
bool vis[N];
int m,n;
void dem(int x)
{
   vis[x] = 1; d++;
   for (auto u : g[x])
   if ( !vis[u] ) dem(u);
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 1; i<=n; i++)
    if (!vis[i] && g[i].size() == 1){
        d = 0;
        dem(i);
        ans += d*(d-1)*(d+1)/3;
    }
    for (int i=1; i<=n; i++)
    if (!vis[i]){
        d = 0;
        dem(i);
        ans += d*((d-1)/2)*((d-1)/2+1) + (d % 2 ? 0 : d * (d/2) );
    }
    cout << ans;
    return 0;
}