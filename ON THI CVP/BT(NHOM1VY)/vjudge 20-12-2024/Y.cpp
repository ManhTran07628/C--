#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<ll,ll> a[N];

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
    ll n,f;
    cin >> n >> f;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        //cout << a[i].fi << ' ' << a[i].se << '\n';
        if(a[i].fi < a[i].se) {
            if(f > 0) {
                ans += min(a[i].fi*2,a[i].se);
                f--;
            }
            else ans += min(a[i].fi,a[i].se);
        }
        else ans += min(a[i].fi,a[i].se);
    }
    cout << ans;
    return 0;
}