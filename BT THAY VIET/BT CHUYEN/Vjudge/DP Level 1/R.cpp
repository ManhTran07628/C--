#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll dp[1030][770][2][2],a[1030][770];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = 1;k <= 2;k++) {
                for(int d = 1;d <= 2;d++) {
                    if(i == 1) {
                        
                    }
                }
            }
        }
    }
    return 0;
}