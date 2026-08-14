#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
int n,m;

ll binpow(ll a,ll b)
{
    if(b <= 0) return 1;
    ll x = binpow(a,b / 2);
    if(b % 2 == 1) return x * x % MOD * a % MOD;
    return x * x % MOD;
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
    cin >> n >> m;
    ll res = 0;
    return 0;
}