#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e7 + 7;
const int MOD = 1e9 + 7;
ll n;

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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    ll res = 0;
    cout << binpow(2,n / 2);
    return 0;
}