#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
vector<ll> b,c;
int main() {
    freopen("tn.inp","r",stdin);
    freopen("tn.out","w",stdout);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    ll tmp = a[0];
    for(ll i = 1;i < n;i++) {
        tmp = (tmp*a[i] / __gcd(tmp,a[i]));
    }
    cout << tmp << endl;
    for(ll i = 0;i < n;i++) {
        cout << tmp / a[i] << " ";
    }
    return 0;
}
