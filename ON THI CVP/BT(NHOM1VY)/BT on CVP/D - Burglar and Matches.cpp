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
    ll n,m;
    cin >> m >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].se >> a[i].fi;
    }
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        if(m >= a[i].se) {
            ans += a[i].fi * a[i].se;
            m-= a[i].se;
        }
        else {
            ans += m*a[i].fi;
            break;
        }
    }
    cout << ans;
    return 0;
}