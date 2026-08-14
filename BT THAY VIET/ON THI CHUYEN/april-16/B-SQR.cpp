#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll d,l,r;
    cin >> d >> l >> r;
    ll ans = 0;
    for(int a = 1;a <= sqrt(d);a++) {
        if(d % a != 0) continue;
        ll b = d / a;
        if((a+b)%2 != 0) continue;
        ll x = (a+b)/2;
        ll y = (b-a)/2;
        if(y < 0 || x <= y) continue;
        ll x2 = x*x;
        ll y2 = y*y;
        if(y2 >= l && x2 <= r && x2 >= y2) ans++;
    }
    cout << ans;
    return 0;
}