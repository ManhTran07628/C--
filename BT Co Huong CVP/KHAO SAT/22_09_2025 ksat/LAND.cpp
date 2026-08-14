#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 200+7;
int n,m,k,a[MM][MM];


int getsum(int x,int y,int u,int v)
{
    return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int ans = 0;
    for(int l = 1;l <= n;l++) {
        for(int w = 1;w <= m;w++) {
            for(int x = 1;x+l-1 <= n;x++) {
                for(int y = 1;y+w-1 <= m;y++) {
                    if(getsum(x,y,x+l-1,y+w-1) <= k) {
                        ans = max(ans,l*w);
                    }
                }
            }
        }
    }
    return 0;
}