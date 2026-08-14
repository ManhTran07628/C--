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
    #define taskname "div"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll q;
    cin >> q;
    while(q--) {
        ll n,m,a,b;
        cin >> n >> m >> a >> b;
        ll k = m - n;
        ll ans = k / a + k / b - k / lcm(a,b);
        cout << k-ans << '\n';
    }
    return 0;
}