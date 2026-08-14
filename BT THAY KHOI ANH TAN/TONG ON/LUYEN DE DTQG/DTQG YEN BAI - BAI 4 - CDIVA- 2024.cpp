#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
ll n,q,a[MM],vis[MM];

namespace subtask1
{
    void solve()
    {
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = a[i];j <= q;j += a[i]) {
                if(!vis[j]) {
                    res++;
                    vis[j] = 1;
                }
            }
        }
        cout << res;
    }
}

namespace subtask2
{
    ll lcm(ll a,ll b)
    {
        return a / __gcd(a,b) * b;
    }

    void solve()
    {
        ll res = 0;
        for(int mask = 1;mask < (1 << n);mask++) {
            ll mul = 0;
            for(int i = 0;i < n;i++) 
                if(mask >> i & 1) {
                    if(mul == 0) mul = a[i+1];
                    mul = lcm(mul,a[i+1]); 
                }

            int sz = __builtin_popcount(mask);
            if(sz % 2) res += q / mul;
            else res -= q / mul;
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "CDIVA"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= 1e5 && q <= 1e5) subtask1::solve();
    else subtask2::solve();
    return 0;
}