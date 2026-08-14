#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "8DIVISIBLE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll maxn = -1e9;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    ll max1 = a[0];
    for(int i = 1;i < n;i++) {
        ll ans= __gcd(max1,a[i]);
        max1 = max1 / ans * a[i];
    }
    max1 = max1-1;
    ll kq = 0;
    for(int i = 0;i < n;i++) {
        kq += max1 % a[i];
    }
    cout << kq;
    return 0;
}
