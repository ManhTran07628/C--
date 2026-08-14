#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    ll n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    ll dem = 0,tong = 0;
    for(int i = 0;i < n;i++) {
        if(tong + a[i] <= m) {
            tong += a[i];
        }
        else {
            tong = 0;
            dem++;
            i--;
        }
    }
    cout << dem+1;
    return 0;
}




