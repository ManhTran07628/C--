#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    while(q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = a[x2][y2] - a[x2][y1-1] - a[x1-1][y2] + a[x1-1][y1-1];
        cout << ans << '\n';
    }
    return 0;
}