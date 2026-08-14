#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n,m;
int check[201][201];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        check[u][v] = 1;
        check[v][u] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            if(check[i][j] || check[j][i]) continue;
            for(int k = j+1;k <= n;k++) {
                if(check[i][k] || check[k][i]) continue;
                if(check[k][j] || check[j][k]) continue;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}