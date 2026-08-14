#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,a[MM];

namespace subtask1
{
    bool sqr(ll x)
    {
        ll sqrx = sqrt(x);
        return sqrx * sqrx == x;
    }

    ll lcm(ll a,ll b)
    {
        return a / __gcd(a,b) * b;
    }

    void solve()
    {
        int res = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++) {
                ll x = lcm(a[i],a[j]) / __gcd(a[i],a[j]);
                res += sqr(x);
            }

        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    subtask1::solve();
    return 0;
}