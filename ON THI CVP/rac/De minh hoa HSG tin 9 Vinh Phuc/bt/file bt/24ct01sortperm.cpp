#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
ll a[N],b[N];
map<ll,ll> c;
int main()
{
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
        c[a[i]] = i;
    }
    sort(b+1,b+n+1);
    for(int i = 1;i <= n;i++) {
        cout << c[b[i]] << " ";
    }
    return 0;
}
