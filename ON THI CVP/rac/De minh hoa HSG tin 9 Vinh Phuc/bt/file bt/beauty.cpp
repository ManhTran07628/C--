#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;
int main()
{
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = a[i-1] + a[i];
        b[i] = min(a[i],b[i-2]);
    }
    ll ans = -1e18;
    for(int i = 1;i <= n;i++) {
        cout << b[i] << " ";
    }
    for(int i = 4;i <= n;i++) {
        ans = max(ans,a[i] - b[i-4]);
    }
    return 0;
}

