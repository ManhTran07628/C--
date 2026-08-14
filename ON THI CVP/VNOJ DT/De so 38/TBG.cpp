#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll x,y,z;
ll check(ll k)
{
    ll cnt = 0,crr = k*y;
    while(crr > 0) {
        crr += y;
        crr -= x;
        if(crr >= 0) cnt++;
        else break;
    }
    return cnt >= z;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TBG"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> x >> y >> z;
    ll l = 0,r = 1e5,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
        cout << mid << '\n';
    }
    cout << ans;
    return 0;
}