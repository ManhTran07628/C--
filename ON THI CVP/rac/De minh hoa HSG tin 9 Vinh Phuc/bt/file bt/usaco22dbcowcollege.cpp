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
    }
    sort(a+1,a+n+1);
    ll max1 = -1,vt = 0;
    for(int i = 1;i <= n;i++) {
        ll tmp = n - i + 1;
        ll kq = tmp * a[i];
        if(max1 < kq) {
            max1 = kq;
            vt = a[i];
        }
    }
    cout << max1 << " " << vt;
    return 0;
}
