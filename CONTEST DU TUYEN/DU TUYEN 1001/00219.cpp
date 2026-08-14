#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
ll n,b[MM];
pii a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1,[] (pii a,pii b){
        if(a.fi != b.fi) return a.fi < b.fi;
        return a.se > b.se;
    });
    for(int i = 1;i <= n;i++) b[i] = a[i].se;
    vector<ll> v;
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(v.begin(),v.end(),b[i]) - v.begin();
        if(pos == v.size()) v.push_back(b[i]);
        else v[pos] = b[i];
    }
    cout << v.size();
    return 0;
}