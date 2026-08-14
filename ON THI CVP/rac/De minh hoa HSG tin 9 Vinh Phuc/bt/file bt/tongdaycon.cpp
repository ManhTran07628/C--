#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
ll a[N];
map<ll,ll> b,c;
int main()
{
    ll n,x,dem = 0;
    cin >> n >> x;
    c[0] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
        dem += c[b[i]-x];
        c[b[i]]++;
    }
    cout << dem;
    return 0;
}
