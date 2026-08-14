#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N],n,h,k,q,a1[N],a2[N];
ll test = LONG_MIN,test1 = LONG_MIN;
ll dem = 0;
ll dem1[N],dem2[N];
int main() {
    cin >> n >> q;
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
        a1[dem1[a[i]]]++;
    }
    for (ll i = 0;i < n;i++) {
        cin >> b[i];
        a2[dem2[b[i]]]++;
    }
    test = max(test,test1);
    while(q--) {
        cin >> k;
        cout << a1[k] << " " << a2[k] << '\n';
    }
    return 0;
}
