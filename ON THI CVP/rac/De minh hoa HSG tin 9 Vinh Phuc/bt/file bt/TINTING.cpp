#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    ll max1 = -1e9,min1 = 1e9;
    for(ll i = 0;i < n;i++) {
        cin >> a[i];
        max1 = max(max1,a[i]);
        min1 = min(min1,a[i]);
    }
    cout << max1 - min1 + 1;
    return 0;
}

