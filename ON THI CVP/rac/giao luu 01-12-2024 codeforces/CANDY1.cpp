#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
ll n;
ll check(ll i)
{
    ll cnt = n;
    ll ans = 0;
    while(cnt > 0) {
        if(cnt >= i) ans += i;
        else {
            ans += cnt;
            break;
        }
        cnt -= i;
        ll tmp = double(cnt) / 10;
        cnt -= tmp;
    }
    if(ans >= n/2) {
        return 1;
    }
    else return 0;
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
    cin >> n;
    ll L = 1,R = 1e18;
    ll fans = n;
    while(L <= R) {
        ll mid = (L+R)/2;
        if(check(mid)) {
            fans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << fans;
    return 0;
}