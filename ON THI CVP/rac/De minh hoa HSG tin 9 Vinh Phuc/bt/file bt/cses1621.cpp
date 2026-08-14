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
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    cout << b.size();
    return 0;
}
