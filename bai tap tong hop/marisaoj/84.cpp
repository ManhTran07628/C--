#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

ll check(ll n)
{
    return (n / 3) + (n / 5) + (n / 7) - (n / 15) - (n / 21) - (n / 35) + (n / 105);
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
    ll k;
    cin >> k;
    ll l = 1,r = 1e18,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid) >= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}