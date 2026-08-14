#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 2e3+7;
int n,m,k;
ll a[MM][MM];

ll get(int x,int y,int u,int v)
{
    return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }

    ll res = 0;      
    for(int i = k;i <= n;i++)
        for(int j = k;j <= m;j++) {

            ll sum = 0;
            int u = i - k + 1, v = j - k + 1;
            int x = u, y = v;
            while(x <= i && y <= j) {
                sum += get(x,v,x,y);
                // cout << x << ' ' << v << ' ' << x << ' ' << y << '\n';
                x++; y++;
            } 
            // cout << '\n';
            res = max(res,sum);

        }      
    cout << res;
    return 0;
}