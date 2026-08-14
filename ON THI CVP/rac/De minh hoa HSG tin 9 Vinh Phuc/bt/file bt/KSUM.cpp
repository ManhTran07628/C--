#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
int main() {
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll tong = 0,max1 = -1e9,dem = 0;
    for(int i = 1;i <= n;i++) {
        tong += a[i];
        dem++;
        if(dem > k) {
            tong -= a[i-k];
        }
        max1 = max(tong,max1);
    }
    cout << max1;
    return 0;
}
