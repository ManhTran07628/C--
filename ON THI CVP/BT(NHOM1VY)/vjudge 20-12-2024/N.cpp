#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
const int N = 1e6 + 7;
multiset<ll> range,f;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "" 
    if(fopen(taskname ".inp", "r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,x;
    cin >> x >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    f.insert(x);
    range.insert(0);range.insert(x);
    for(int i = 1;i <= n;i++) {
        auto it = range.upper_bound(a[i]);
        ll r = *it;
        if(it != f.begin()) --it;
        ll l = *it;
        auto m = f.lower_bound(r-l);
        f.erase(m);
        f.insert(a[i] - l);
        f.insert(r - a[i]);
        range.insert(a[i]);
        cout << *f.rbegin() << ' ';
        // cout << l << ' ' << r << '\n';
        // for(auto j:f) {
        //     cout << j << ' ';
        // }
        // cout << '\n' << '\n';
    }
    return 0;
}