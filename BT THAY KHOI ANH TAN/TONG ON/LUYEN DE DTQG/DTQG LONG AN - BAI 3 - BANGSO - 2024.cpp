#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 500 + 7;
int n,m,a[MM][MM],ps[MM][MM];

int getsum(int x,int y,int u,int v)
{
    return ps[u][v] - ps[u][y-1] - ps[x-1][v] + ps[x-1][y-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "BANGSO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            ps[i][j] = -ps[i-1][j-1] + ps[i-1][j] + ps[i][j-1] + a[i][j];
        }
    }

    int res = -1e9;
    for(int x1 = 1;x1 <= n;x1++) {
        for(int x2 = x1;x2 <= n;x2++) {
            int sum = 0;
            for(int y = 1;y <= m;y++) {
                int s = getsum(x1,y,x2,y);
                sum += s;
                res = max(res,sum);
                if(sum < 0) sum = 0;
            }
        }
    }
    cout << res;
    return 0;
}