#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll n,q,a[MM],ps[MM];

ll get(ll k,ll x,ll y)
{
    return ( ps[x] + k * y ) - ( ps[n] - ps[n - y] - k * y );
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "APEN"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) ps[i] = ps[i-1] + a[i];
    // cout << get(15,2,1);
    while(q--) {
        ll k,m; cin >> k >> m;
        int L = 0,R = lower_bound(a+1,a+m+1,k) - a - 1;
        ll res = 0;
        while(L <= R) {
            int m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
            if(get(k,m1,m - m1) < get(k,m2,m - m2)) {
                res = m1;
                R = m2 - 1;
            }
            else {
                res = m2;
                L = m1 + 1;
            }
        }
        cout << get(k,res,m - res) << '\n';
    }
    return 0;
}