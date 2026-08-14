#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    double c,h; cin >> c >> h;
    double r = c / 2;
    if(h <= r) {
        double res = c * h / 2;
        cout << fixed << setprecision(1) << res;
    }
    else cout << -1;
    return 0;
}