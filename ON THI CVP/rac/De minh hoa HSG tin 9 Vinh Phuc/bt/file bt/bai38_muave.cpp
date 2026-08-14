#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main()
{
    freopen("MUAVE.inp","r",stdin);
    freopen("MUAVE.out","w",stdout);
    ll n;
    cin >> n;
    ll tong = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tong += a[i];
    }
    ll chenhlc = 1e18;
    ll tong1 = 0;
    for(int i = 1;i <= n;i++) {
        ll tong2 = tong - a[i];
        chenhlc = min(abs(tong1-(tong2 - tong1)),chenhlc);
        tong1 += a[i];
    }
    cout << chenhlc;
    return 0;
}
