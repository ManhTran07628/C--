#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<ll,ll>

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    ll x,n = 0; cin >> x;
    string s;
    while(x != 0) {
        s.push_back( (x % -2ll + 2ll) % 2ll + '0');
        x = ceil((double)x / -2ll);
        n++;
    }
    cout << n << '\n';
    // reverse(s.begin(),s.end());
    for(auto p:s) cout << p << ' ';


    return 0;
}