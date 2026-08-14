#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
int d[101][101];
int n,m;
void Floyd_Warshall()
{
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            d[i][j] = oo;
        }
    }
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    Floyd_Warshall();
    int ans = 0,maxp = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            ans += d[i][j];
            maxp = max(maxp,d[i][j]);
        }
    }
    cout << maxp << ' ';
    cout << ans - maxp;
    return 0;
}