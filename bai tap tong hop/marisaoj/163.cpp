#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
ll f[MM],finv[MM];

ll binpow(ll a,ll b)
{
    ll res = 1;
    while(b > 0) {
        if(b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

ll C(ll k,ll n)
{
    return (f[n] * finv[n - k] % MOD * finv[k] % MOD) % MOD;
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
    int a,b,n; cin >> a >> b >> n;
    f[0] = 1;
    for(int i = 1;i < MM;i++) f[i] = (f[i - 1] * i) % MOD;
    finv[MM - 1] = binpow(f[MM - 1],MOD - 2);
    for(int i = MM - 1;i >= 1;i--)
        finv[i - 1] = (finv[i] * i) % MOD;

    cout << C(n,a) * C(n,b) % MOD;
    return 0;
}