#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q,x,y,z;
    cin >> q >> x >> y >> z;
    if(q > 3) {
        cout << 0;
        return 0;
    }
    if(q == 1) {
        cout << x + y + z;
    }
    else if(q == 2) {
        ll ans = x*y-min(x,y) + x*z-min(x,z) + y*z-min(y,z);
        cout << ans;
    }
    else if(q == 3) {
        int t = x+y+z-max({x,y,z})-min({x,y,z});
        ll ans = (max({x,y,z})-2)*(t-1)*min({x,y,z});
        cout << ans;
    }
    return 0;
}