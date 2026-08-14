#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
const int MM = 20;
int n,m,deg[MM];
ll dist[MM][MM],dp[1 << 15];


void init(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++)   
            dist[i][j] = oo;
    for(int i = 1;i <= m;i++) {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        deg[u]++; deg[v]++;
        dist[u][v] = dist[v][u] = w;
    }
}

void solve()
{
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                
            }
        }
    }

    for(int i = 1;i < (1 << n);i++) dp[i] = oo;

    for(int mask = 1;mask < (1 << n);mask++) {
        vector<int> valid;
        for(int i = 0;i < n;i++) 
            if((mask >> i & 1) && deg[i+1] % 2) valid.push_back(i+1);

        for(auto i:valid) {
            for(auto j:valid) {
                if(i == j) continue;
                dp[mask] = min(dp[ mask ],dp[ (mask ^ (1 << (i-1))) ^ (1 << (j-1)) ] + dist[i][j]);
                cout << i+1 << ' ' << j+1 << ' ' << dp[mask] << '\n';
            }
        }
    }

    cout << dp[(1 << n)-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}