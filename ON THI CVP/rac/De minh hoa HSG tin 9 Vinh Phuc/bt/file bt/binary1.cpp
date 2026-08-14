#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        a[i].first = a1;
        a[i].second = i;
    }
    sort(a+1,a+n+1);
    while(m--) {
        ll l,r,x;
        cin >> l >> r >> x;
        ll vt = upper_bound(a+l+1,a+r+1,make_pair(x,LLONG_MAX)) - a;
        if(a[vt].second >= l && a[vt].second <= r) {
            cout << a[vt].second << '\n';
        }
        else {
            ll vt1 = upper_bound(a+l+1,a+vt+1,make_pair(a[l].first,LLONG_MAX)) - a;
            if ((a[vt1].second >= l && a[vt1].second <= r) || vt1 != vt) {
                cout << vt1 << '\n';
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}