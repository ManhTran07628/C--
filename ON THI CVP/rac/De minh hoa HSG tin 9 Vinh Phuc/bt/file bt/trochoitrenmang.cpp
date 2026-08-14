#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
ll a[N],b[N];
int main()
{
    ll n;
    cin >> n;
    ll t = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        ll tmp = max(b[i] * (-1) + (b[n]-b[i]),b[i] + (b[n]-b[i]) * (-1));
        max1 = max(max1,tmp);
    }
    cout << max1;
    return 0;
}

