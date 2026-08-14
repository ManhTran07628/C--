#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int LOG = 30;
int n,q,up[MM][LOG + 1];

int bin_lifting(int u,ll k)
{
    for(int j = LOG;j >= 0;j--) {
        if((k >> j) & 1)
            u = up[u][j];
    }
    return u;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        int nxt; cin >> nxt;
        up[i][0] = nxt;
    }
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
    while(q--) {
        ll x,k; cin >> x >> k;
        cout << bin_lifting(x,k) << '\n';
    }
    return 0;
}