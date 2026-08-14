#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll mau = lcm(b,d);
    ll tu = (mau/b*a) + (mau/d*c);
    ll x = __gcd(tu,mau);
    tu /= x;
    mau /= x;
    cout << tu << ' ' << mau;
    return 0;
}