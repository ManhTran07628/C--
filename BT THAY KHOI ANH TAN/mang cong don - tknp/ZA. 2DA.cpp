#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[1000][1000],d[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,q;
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    while(q--) {
        ll x1,y1,x2,y2,val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        d[x1][y1] += val;
        d[x1][y2+1] -= val;
        d[x2+1][y1] -= val;
        d[x2+1][y2+1] += val;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            cout << a[i][j]+d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}