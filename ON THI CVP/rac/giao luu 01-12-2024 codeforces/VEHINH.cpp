#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;

ll lcm(ll a,ll b) {
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
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    ll cna = n / a;
    ll cnb = n / b;
    ll cnab = n / lcm(a,b);
    ll ans = (cna - cnab) * c + (cnb - cnab) * d + cnab * max(c,d);
    cout << ans;
    return 0;
}