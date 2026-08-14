#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> c;
ll tmp = 1e6;
int main() {
    ll n,k;
    cin >> n >> k;
    c[0] = 1;
    ll dem = 0;
    ll tongtt = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tongtt += a[i];
        ll tmp = tongtt - k*i;
        dem += c[tmp];
        c[tmp]++;
    }
    cout << dem;
    return 0;
}