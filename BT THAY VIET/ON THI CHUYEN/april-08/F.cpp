#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll z[1000],a[1000],b[1000];
ll n,p;
bool check(ll x)
{
    ll s = 0;
    for(int i = 1;i <= n;i++) {
        if(x <= z[i]) s += a[i]*x;
        else s += a[i]*z[i]+b[i]*(x-z[i]);
    }
    return s >= p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    for(int i = 1;i <= n;i++) {
        cin >> z[i] >> a[i] >> b[i];
    }
    ll l = 1,r = 1e12,ans = 0;
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