#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e6 + 7;
ll mang[N];
ll tmp = 3e6;
int main() {
    freopen("sokhoemanh.inp","r",stdin);
    freopen("sokhoemanh.out","w",stdout);
    ll a,b;
    cin >> a >> b;
    ll dem = 0;
    for(ll i = 2;i < tmp;i++) {
        for(ll j = i*2;j < tmp;j +=i) {
            mang[j] += i;
        }
    }
    for (int i = a; i <= b; i++) {
        if (mang[i] > i) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}

