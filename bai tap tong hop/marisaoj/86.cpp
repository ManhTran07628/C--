#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll n,k;
ll check(ll f)
{
    ll cnt = 1,crr = a[1];
    for(int i = 2;i <= n;i++) {
        if(a[i] - crr >= f) {
            cnt++;
            crr = a[i];
            if(cnt == k) return 1;
        }
    }
    return 0;
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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll l = 0,r = 1e18,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = max(mid,ans);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}