#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],dau[N],cuoi[N],b[N];
int main() {
    freopen("thicong.inp","r",stdin);
    freopen("thicong.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dau[i] = dau[i-1] + a[i];
    }
    for(int i = 1;i <= n;i++) {
        cuoi[i] = cuoi[i-1] + a[n-i+1];
    }
    ll max1 = -1e10;
    for(int i = 0;i <= k;i++) {
        max1 = max(max1,dau[i]+cuoi[k-i]);
    }
    cout << max1;
    return 0;
}




