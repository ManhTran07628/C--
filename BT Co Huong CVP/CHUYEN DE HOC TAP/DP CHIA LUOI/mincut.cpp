#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,m,k;
ll a[MM][MM];

ll getsum(int i,int j,int u,int v)
{
    return a[u][v] - a[i-1][v] - a[u][j-1] + a[i-1][j-1];
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

    // cout << 36;
    while(k--) {
        int x,y,u,v; cin >> x >> y >> u >> v;

        ll res = oo;
        int L = y, R = v - 1, pos = y;

        while(L <= R) {
            int mid = (L + R) / 2;
            ll get1 = getsum(x,y,u,mid);
            ll get2 = getsum(x,mid+1,u,v);
            if(get1 == get2) {
                res = 0;
                break;
            }
            res = min(res,abs(get1-get2));
            if(get1 > get2) R = mid - 1;
            else L = mid + 1;
        }

        L = x, R = u - 1, pos = 1;

        while(L <= R) {
            int mid = (L + R) / 2;
            ll get1 = getsum(x,y,mid,v);
            ll get2 = getsum(mid+1,y,u,v);
            if(get1 == get2) {
                res = 0;
                break;
            }
            res = min(res,abs(get1-get2));
            if(get1 > get2) R = mid - 1;
            else L = mid + 1;
        }
        cout << res << '\n';
    }
    
        
    return 0;
}