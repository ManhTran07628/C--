#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
pii a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,[] (pii a,pii b){
        if(a.fi != b.fi) return a.fi < b.fi;
        return a.se > b.se;
    });

    for(int i = 1;i <= n;i++) cout << a[i].fi << ' ' << a[i].se << '\n';
    vector<int> v;
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(v.begin(),v.end(),a[i].se) - v.begin();
        if(pos == v.size()) v.push_back(a[i].se);
        else v[pos] = a[i].se;
    }
    cout << v.size() << '\n';
    return 0;
}