#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;

vector<ll> v;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m,n,s; cin >> m >> n >> s;
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++) {
            ll x; cin >> x;
            v.push_back(x);
        }

    ll res = 0;
    sort(v.begin(),v.end());
    for(int i = 0;i < v.size();i++) {
        ll val = upper_bound(v.begin(),v.end(),s - v[i]) - v.begin() - 1;
        if(val >= 0 && i != val) res = max(res,v[val] + v[i]);
    }
    cout << (res == 0 ? -1 : res);
    return 0;
}