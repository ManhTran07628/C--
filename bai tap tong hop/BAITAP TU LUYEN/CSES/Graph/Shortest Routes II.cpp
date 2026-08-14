#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 500+7;
int n,m,q,d[MM][MM],adj[MM][MM];


void Floyd_Warshall()
{
    for(int k = 1;k <= n;k++) {
        for(int u = 1;u <= n;u++) {
            for(int v = 1;v <= n;v++) {
                if(d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                }
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            d[i][j] = oo;
        }
    }
    for(int i = 1;i <= n;i++) d[i][i] = 0;
    for(int i = 1;i <= m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        d[a][b] = min({d[a][b],w,d[b][a]});
        d[b][a] = min({d[a][b],w,d[b][a]});
    }
    Floyd_Warshall();
    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << (d[a][b] != oo ? d[a][b] : -1) << '\n';
    }
    return 0;
}