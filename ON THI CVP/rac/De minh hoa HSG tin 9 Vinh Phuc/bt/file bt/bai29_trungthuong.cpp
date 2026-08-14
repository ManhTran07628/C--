#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    freopen("trungthuong.inp","r",stdin);
    freopen("trungthuong.out","w",stdout);
    ll n;
    cin >> n;
    int dem = 0;
    while(n--) {
        ll k;
        cin >> k;
        ll max1 = -1;
        ll min1 = 10;
        while(k > 0) {
            ll tmp = k % 10;
            max1 = max(max1,tmp);
            min1 = min(min1,tmp);
            k /= 10;
        }
        if(min1 == 0) continue;
        if(max1 % min1 == 0) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}

