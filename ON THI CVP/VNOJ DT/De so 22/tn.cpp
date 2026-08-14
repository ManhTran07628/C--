#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tn"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll x1,x2;
    cin >> x1 >> x2;
    ll lcm = x1 / __gcd(x1,x2) * x2;
    cout << lcm << "\n" << lcm / x1 << " " << lcm / x2;
    return 0;
}