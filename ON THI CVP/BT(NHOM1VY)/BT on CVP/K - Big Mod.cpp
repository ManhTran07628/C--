#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

ll binpow(ll a,ll b,ll m)
{
    ll ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % m;
        b /= 2;
        a = a * a % m;
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
    ll a,b,m;
    while(cin >> a >> b >> m) cout << binpow(a,b,m) << '\n';

    return 0;
}