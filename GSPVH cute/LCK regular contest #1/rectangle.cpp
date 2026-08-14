#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int lim = 407;
int n,vis[lim][lim];



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "rectangle"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    int min_x = lim, min_y = lim, max_x = 0, max_y = 0;
    for(int i = 1;i <= n;i++) {
        int x,y,c; cin >> x >> y >> c;
        x += 200; y += 200;
        min_x = min(min_x,x);
        min_y = min(min_y,y);
        max_x = max(max_x,x);
        max_y = max(max_y,y);
        vis[x][y] = c;
    }

    int res = 0;
    for(int i = min_x;i <= max_x;i++) 
        for(int j = i + 1;j <= max_x;j++) {

            int mp[5][5] = {};

            for(int k = min_y;k <= max_y;k++) {
                int c1 = -1, c2 = -1;
                if(vis[i][k] == 0 || vis[j][k] == 0) continue;
                if(vis[i][k] == vis[j][k]) continue;

                for(int c = 1;c <= 4;c++) {
                    if(vis[i][k] == c || vis[j][k] == c) continue;
                    if(c1 == -1) {
                        c1 = c;
                        continue;
                    }
                    if(c2 == -1) {
                        c2 = c;
                        continue;
                    }
                }

                // cout << c1 << ' ' << c2 << ' ' << vis[i][k] << ' ' << vis[j][k] << '\n';

                res += mp[c1][c2];

                mp[ vis[i][k] ][ vis[j][k] ]++;
                mp[ vis[j][k] ][ vis[i][k] ]++;
            }
        }
    cout << res;

    return 0;
}