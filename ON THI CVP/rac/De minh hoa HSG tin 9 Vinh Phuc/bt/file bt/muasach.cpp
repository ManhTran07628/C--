
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
    sort(a+1,a+n+1,greater<ll>());
    ll kq = 0;
    for(int i = 1;i <= n;i++) {
        if(i % 3 != 0) {
            kq += a[i];
        }
    }
    cout << kq;
    return 0;
}
