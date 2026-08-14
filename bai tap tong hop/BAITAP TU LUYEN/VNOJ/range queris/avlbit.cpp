#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int LOG = 18;
int n,q,a[MM],Min[MM][LOG + 1];
ll ps[MM];

ll get(int l,int r)
{
    int k = __lg(r - l + 1);
    return min(Min[l][k],Min[r - (1 << k) + 1][k]);
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
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
        Min[i][0] = a[i];
    }
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++)
            Min[i][j] = min(Min[i][j-1],Min[i + (1 << (j - 1))][j - 1]);

    while(q--) {
        int l,r; cin >> l >> r;
        int N = (r - l + 1);
        ll P = get(l,r);
        ll S = ps[r] - ps[l-1];
        ll x = 2 * (S - N * P) / ((N - 1) * N);
        // cout << x << '\n';
        if(N * P + (N - 1) * N / 2 * x == S && x > 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}