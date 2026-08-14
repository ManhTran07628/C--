#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e7 + 7;
const int sz = 43;
ll n,k;

ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
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
    cin >> n >> k;
    ll L = 1;
    bool ok = 0;
    for(ll i = 1;i <= k;i++) {
        if(L > n) break;
        if(i >= sz) break;
        ll x = lcm(L,i);
        // cout << i << ' ' << x << '\n';
        if(i == k) ok = 1;
        L = x;
    }
    if(!ok) cout << 1;
    else {
        ll t = (n - 1) / L;
        // if(L * t + 1 > n) cout << 
        cout << L * t + 1;
    }
    return 0;
}