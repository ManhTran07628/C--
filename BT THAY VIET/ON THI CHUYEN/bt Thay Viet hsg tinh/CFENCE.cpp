#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
set<ll> f;
ll n;
ll cntnums(ll r)
{
    map<ll,ll> dem;
    for(int i = 1;i <= n;i++) { 
        dem[a[i]]++;
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        if(r == a[i]) {
            ans++;
        }
        else if(r > a[i]) {
            if(a[i]*2==r) {
                ll res = dem[a[i]] / 2;
                dem[a[i]] = dem[a[i]] - res - res;
                ans += res;
            }
            else {
                ll x = r-a[i];
                ll res = min(dem[x],dem[a[i]]);
                ans += res;
                dem[x] -= res;
                dem[a[i]] -= res;
            }
        }
    }
    return ans;
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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        f.insert(a[i]);
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            f.insert(a[i]+a[j]);
        }
    }
    ll max1 = -1e9;
    for(auto c:f) {
        ll tmp = cntnums(c);
        max1 = max(max1,tmp);
    }
    cout << max1;
    return 0;
}
