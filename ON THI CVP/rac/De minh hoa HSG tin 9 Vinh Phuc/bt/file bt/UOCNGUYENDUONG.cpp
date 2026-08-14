#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<ll> a;
int main() {
//    freopen("UOC.inp","r",stdin);
//    freopen("UOC.out","w",stdout);
    ll n;
    cin >> n;
    for(ll i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            ll tmp = floor(sqrt(i));
            if(tmp * tmp == i) {
                a.push_back(i);
            }
            tmp = floor(sqrt(n/i));
            if(tmp * tmp == i)
                a.push_back(n/i);
        }
    }
    ll tong = 0;
    sort(a.begin(),a.end());
    for(auto c: a) {
        cout << c << " ";
    }
    return 0;
}
