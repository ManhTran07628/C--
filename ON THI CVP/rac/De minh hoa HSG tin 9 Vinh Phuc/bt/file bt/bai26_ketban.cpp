#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
map<ll,ll> lt;
int main() {
    freopen("FRIEND.inp","r",stdin);
    freopen("FRIEND.out","w",stdout);
    ll n,B;
    cin >> n >> B;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        dem += lt[B - a[i]];
        lt[a[i]]++;
    }
    cout << dem;
    return 0;
}

