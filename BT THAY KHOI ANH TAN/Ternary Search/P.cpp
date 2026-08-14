#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q;
ll a[MM],ps[MM];

ll f(int x,ll k,ll m)
{
    int y = m - x;
    return ps[x] + y * k - (ps[n] - ps[n - y] - y * k);
}

void solve(ll k,ll m)
{
    ll pos = lower_bound(a+1,a+m+1,k) - a - 1;
    int L = 0,R = pos;
    ll ans = 0;
    while(L <= R) {
        int m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
        if(f(m1,k,m) < f(m2,k,m)) {
            ans = m1;
            R = m2 - 1;
        }
        else {
            ans = m2;
            L = m1 + 1;
        }
    }
    cout << f(ans,k,m) << '\n';
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) 
        ps[i] = ps[i-1] + a[i];
    while(q--) {
        ll k,m;
        cin >> k >> m;
        solve(k,m);
    }
    return 0;
}