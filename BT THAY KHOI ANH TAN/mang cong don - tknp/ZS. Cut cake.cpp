#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 300+7;
int a[MAXN][MAXN];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    int ans = -1e18;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int x = i+1;x <= n;x++) {
                for(int y = j+1;y <= m;y++) {
                    int sum = a[x][y]-a[x][j-1]-a[i-1][y]+a[i-1][j-1];
                    ans = max(ans,sum);
                }
            }
        }
    }
    cout << ans;
    return 0;
}