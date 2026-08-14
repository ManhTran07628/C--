#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll tmp = 1e12;

int main() {
    freopen("debien.inp","r",stdin);
    freopen("debien.out","w",stdout);
    ll n;
    cin >> n;
    ll dem = 0;
    while(n--) {
        ll L,R;
        cin >> L >> R;
        ll dau = ceil(sqrt(L));
        ll cuoi = floor(sqrt(R));
        dem += cuoi - dau + 1;
    }
    cout << dem;
    return 0;
}


