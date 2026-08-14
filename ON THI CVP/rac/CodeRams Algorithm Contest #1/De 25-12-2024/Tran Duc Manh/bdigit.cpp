#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll t;


unsigned ll binpow(ll b)
{
    unsigned ll a = 2;
    unsigned ll ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a;
        a *= a;
        b /= 2;
    }
    return ans;
}

ll solve(unsigned ll n)
{
    ll cnt = 0;
    while(n > 1) {
        ll f = ceil(log2(n+1)-1);
        unsigned ll x = binpow(f);
        n -= x;
        cnt++;
    }
    if(n == 0) return cnt % 2 == 1;
    if(n == 1) return cnt % 2 == 0; // neu 
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "bdigit"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    while(t--) {
        unsigned ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}