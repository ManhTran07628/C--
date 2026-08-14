#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
ll tmp = 1e6;
int main() {
    ll n;
    cin >> n;
    for(ll i = 0;i <= tmp;i++) {
        a[i] = 1;
    }
    a[0] = 0,a[1] = 0;
    for(ll i = 2;i <= tmp;i++) {
        if(a[i] == 1) {
            for(ll j = i*i;j <= tmp;j+=i) {
                a[j] = 0;
            }
        }
    }
    ll dem = 0;
    for(ll i = 0;i <= n/2;i++) {
        if(a[i] == 1 && a[n-i] == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}
