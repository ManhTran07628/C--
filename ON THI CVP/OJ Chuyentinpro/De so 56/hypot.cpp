#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "hypot"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll d;
    cin >> d;
    ll ans = d;
    for(ll x = 0;x * x <= d;x++) {
        ll y1 = floor(sqrt(d-x*x));
        ll y2 = ceil(sqrt(d-x*x));
        ll a1 = abs(x*x+y1*y1-d);
        ll a2 = abs(x*x+y2*y2-d);
        ans = min({ans,a1,a2});
    }
    cout << ans;
    return 0;
}