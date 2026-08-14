#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
#define ull unsigned long long
ll a[N];
ll n,t;
bool check(ll k)
{
    ll ans = 0;
    for(int i = 1;i <= n;i++) ans += k/a[i];
    return ans >= t;
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
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll l = 1,r = 1e12,ans = 1e12;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}