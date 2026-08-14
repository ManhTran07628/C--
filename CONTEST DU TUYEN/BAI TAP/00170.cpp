#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
int n;
map<ll,ll> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        mp[i] += a;
    }
    ll res = 0;
    for(int i = 1;i < n;i++) {
        res += min(mp[i],mp[i+1]);
    }
    cout << res;
    return 0;
}