#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    string s; cin >> s;
    ll a = 0, b = 1;
    for(auto c:s) {
        a = a * 10 + (c - '0');
        b *= 10;
    }
    // cout << a << ' ' << b << '\n';
    ll f = __gcd(a,b);
    a /= f; b /= f;
    if(0 < a && a < b && b < 1000000) {
        cout << "YES" << '\n' << a << ' ' << b;
    }
    else cout << "NO";
    // cout << a << ' ' << b;
    
    return 0;
}