#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll g1 = a[n / 2];   
    ll g2 = b[n / 2];
    ll tong = 0;
    for (ll i = 0; i < n; i++) {
        tong += abs(g1 - a[i]) + abs(g2 - b[i]);
    }
    cout << tong << '\n';
    return 0;
}
