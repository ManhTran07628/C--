#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;
int main()
{
    ll n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a,a+n,greater<ll>());
    ll j = 0;
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] + k <= a[j]) {
            j++;
        }
        else {
            dem+= a[i];
        }
    }
    cout << dem;
    return 0;
}
