#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


ll digitsum(ll k)
{
    ll sum = 0;
    for(ll i = 1;i * i <= k;i++) {
        if(k % i == 0) {
            sum += i;
            if(k / i != i) sum += k / i;
        }
    }
    return sum;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "GHH"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    vector<int> res;
    for(int i = 1;i <= n;i++) {
        ll a; cin >> a;
        if(a * 2 <= digitsum(a)) res.push_back(a);
    }
    cout << res.size() << '\n';
    for(auto x:res) cout << x << '\n';
    return 0;
}