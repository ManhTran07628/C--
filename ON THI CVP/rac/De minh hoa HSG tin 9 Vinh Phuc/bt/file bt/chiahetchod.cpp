#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
ll a[N],b[N],c[N];
int main()
{
    ll n,d;
    cin >> n >> d;
    c[0] = 1;
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = (a[i]%d+d)%d;
        b[i] = (b[i-1] + a[i])%d;
        dem += c[b[i]];
        c[b[i]]++;
    }
    cout << dem;
    return 0;
}
