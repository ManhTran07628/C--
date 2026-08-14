#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<ll,ll> a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    ll ans = 0;
    for(ll i = 1;i <= n;i++) {
        ll t = i,sum = 0;
        for(int j = 1;j <= n;j++) {
            if(t-k <= a[j].fi && a[j].fi <= t+k) sum += a[j].se;
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}