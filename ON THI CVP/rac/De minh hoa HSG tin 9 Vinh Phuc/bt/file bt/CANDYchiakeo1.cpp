#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll min1 = 1e9;
    for(int i = 1;i <= n;i++) {
        ll ans = abs((b[i] - b[0]) - (b[n] - b[i]));
        min1 = min(ans,min1);
    }
    cout << min1;
    return 0;
}
