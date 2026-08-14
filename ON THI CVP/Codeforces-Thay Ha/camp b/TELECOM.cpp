#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll n,c;
ll check(ll k)
{
    ll cnt = 0,crr = a[1];
    for(int i = 2;i <= n;i++) {
        if(a[i] - crr >= k) {
            cnt++;
            crr = a[i];
        }
    }
    return cnt < c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TELECOM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> c;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll l = 0,r = 1e9,ans = 1e9;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}