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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].se >> a[i].fi;
    }
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    // for(int i = 1;i <= n;i++) {
    //     cout << a[i].fi << " " << a[i].se << '\n';
    // }
    ll cnt = 1,ans = 0;
    for(int i = 1;i <= n;i++) {
        if(cnt > 0) {
            ans += a[i].se;
            cnt += a[i].fi;
            cnt--;
        }
        else break;
    }
    cout << ans;
    return 0;
}