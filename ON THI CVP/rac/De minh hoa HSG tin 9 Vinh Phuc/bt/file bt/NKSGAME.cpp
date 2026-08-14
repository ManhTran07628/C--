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
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    ll min1 = 1e9;
    for(int i = 1;i <= n;i++) {
        ll L = lower_bound(b+1,b+n+1,-a[i])-b;
        ll R = upper_bound(b+1,b+n+1,-a[i])-b-1;
    }
    return 0;
}

