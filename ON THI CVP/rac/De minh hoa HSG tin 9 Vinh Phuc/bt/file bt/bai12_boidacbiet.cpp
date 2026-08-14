#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll tmp = 1e6;
int main() {
    freopen("bai04.inp","r",stdin);
    freopen("bai04.out","w",stdout);
    ll n;
    cin >> n;
    ll i = n;
    while(true) {
        ll tmp = i;
        bool kt = true;
        while(tmp > 0) {
            ll ans = tmp % 10;
            if(ans != 1) {
                if(ans != 0) {
                    kt = false;
                    break;
                }
            }
            tmp /= 10;
        }
        if(kt == false) {
            i+=n;
        }
        else if(kt == true) {
            if(i % n == 0) {
                cout << i;
                return 0;
            }
            i+=n;
        }
    }
    return 0;
}
