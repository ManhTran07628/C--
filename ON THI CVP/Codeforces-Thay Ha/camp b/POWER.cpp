#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

ll binpow(ll a,ll b,ll MOD)
{
    ll ans = 1;
    a = a % MOD;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,n,m;
    cin >> a >> n >> m;
    ll x = binpow(a,n,m);
    cout << x;
    return 0;
}