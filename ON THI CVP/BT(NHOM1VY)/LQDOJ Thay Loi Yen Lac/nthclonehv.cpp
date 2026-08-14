#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a,b,n;

ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
}

ll check(ll k)
{
    return k / a + k / b - k / lcm(a,b);
}

void solve()
{
    ll l = 1,r = 1e18,ans;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid) >= n) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';
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
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        solve();
    }
    return 0;
}