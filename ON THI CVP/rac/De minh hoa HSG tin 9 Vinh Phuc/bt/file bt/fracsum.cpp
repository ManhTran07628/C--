#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

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
    ll mau = b / __gcd(b,d) * d;
    a = a * (mau / b);
    c = c * (mau / d);
    ll tuso = a + c;
    ll uschung = __gcd(tuso,mau);
    ll tusau = tuso / uschung;
    ll mausau = mau / uschung;
    cout << tusau << " " << mausau;
    return 0;
}