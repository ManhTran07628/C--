#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a,b,p;



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
    cin >> a >> b >> p;
    a = a % p;
    ll a1 = a,b1 = b;
    ll ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % p;
        a = a * a % p;
        b /= 2;
    }
    cout << a1 << "^" << b1 << " mod " << p << "=" << ans;
    return 0;
}