#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll tmp = 1e6;
int main() {
    freopen("bai02.inp","r",stdin);
    freopen("bai02.out","w",stdout);
    ll a,b;
    cin >> a >> b;
    int dem = 0;
    for(ll i = a;i <= b;i++) {
        ll tmp = i;
        ll daonguoc = 0;
        while(tmp > 0) {
            ll ans = tmp % 10;
            daonguoc = daonguoc * 10 + ans;
            tmp /= 10;
        }
        if(__gcd(daonguoc,i) == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}

