#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ld long double
const int N = 1e6+7;
ll a[N];
ll w,l,x;

ll solve(ll k)
{
    ll f = double(w+k)/(w+k+l)*100;
    return f >= x;
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
    cin >> w >> l >> x;
    ll lo = 0,hi = 1e18,ans = 1e18;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(solve(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans;
    return 0;
}