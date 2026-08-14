#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
map<ll,ll> a;
int main() {
    freopen("cotmoc.inp","r",stdin);
    freopen("cotmoc.out","w",stdout);
    ll L,R;
    cin >> L >> R;
    for(ll i = L;i <= R;i++) {
        ll ans = i;
        while(ans > 0) {
            ll tmp = ans % 10;
            a[tmp]++;
            ans /= 10;
        }
    }
    for(int i = 0;i < 10;i++) {
        cout << a[i] << endl;
    }
    return 0;
}





