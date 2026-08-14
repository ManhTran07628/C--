#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
pair<ll,ll> p[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "AIRCON"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    for(int i = 1;i <= m;i++) {
        cin >> p[i].fi >> p[i].se;
    }
    sort(p+1,p+m+1,greater<pair<ll,ll>>());
    for(int i = 1;i <= m;i++) {
        for(int j = i+1;j <= m;j++) {
            if(p[i].fi >= p[j].fi && p[i].se < p[j].se) {
                p[j].fi = p[i].fi;
                p[j].se = p[i].se;
            }
        }
    }
    sort(p+1,p+m+1);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll pos = lower_bound(p+1,p+m+1,make_pair(a[i],0ll)) - p;
        ans += p[pos].se;
    }
    cout << ans;
    return 0;
}
