#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    freopen("TROMVANG.inp","r",stdin);
    freopen("TROMVANG.out","w",stdout);
    ll k;
    ll m,n,q;
    cin >> k >> m >> n >> q;
    ll k1 = k;
    ll max1 = max(m,max(n,q));
    ll max3 = min(m,min(n,q));
    ll max2 = m+n+q-max1-max3;
    ll dem = 0;
    if(k >= max1) {
        dem += max1;
        k -= max1;
    }
    if(k >= max2) {
        dem += max2;
        k -= max2;
    }
    if(k >= max3) {
        dem += max3;
        k -= max3;
    }
    if(max2 + max3 <= k1) {
        cout << max(dem,max2+max3);
        return 0;
    }
    cout << dem;
    return 0;
}

