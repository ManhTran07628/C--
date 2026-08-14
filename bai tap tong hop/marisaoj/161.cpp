#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
ll f[MM],finv[MM];

ll C(int k,int n)
{
    return (f[n] * finv[n - k] % MOD * finv[k]) % MOD;
}

ll binpow(ll a,ll b)
{
    if(b == 0) return 1;
    ll x = binpow(a,b / 2);
    if(b % 2 == 0) return x * x % MOD;
    return x * x % MOD * a % MOD;
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
    int n,k,p; cin >> n >> k >> p;
    if(1ll * k * p > 1ll * n) {
        cout << 0;
        return 0;
    }
    f[0] = 1;
    for(int i = 1;i < MM;i++) f[i] = (f[i - 1] * i) % MOD;
    finv[MM - 1] = binpow(f[MM - 1],MOD - 2);
    for(int i = MM - 1;i >= 1;i--)
        finv[i - 1] = (finv[i] * i) % MOD;

    cout << C(k - 1,n - p * k + k - 1);
    return 0;
}