#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N];
set<ll> b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll i = 2;i <= N;i++) {
        if(a[i] == 0) {
            for(ll j = i;j <= N;j+=i) {
                a[j] = i;
            }
        }
    }
    ll q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        while(n > 1) {
            b.insert(a[n]);
            n /= a[n];
        }
        for(auto c:b) {
            cout << c << " ";
        }
        cout << endl;
        b.clear();
    }
    return 0;
}

