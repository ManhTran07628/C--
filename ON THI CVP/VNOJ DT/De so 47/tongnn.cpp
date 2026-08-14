#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tongnn"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    ll ans = 1e9;
    for(ll x = 1;x <= sqrt(n/m);x++) {
        if(__gcd(x,n/x) == 1 && n % (n/x) == 0) {
            ans = min(ans,x + n/x);
        }
    }
    cout << ans;
   // cout << ans*m;
    return 0;
}