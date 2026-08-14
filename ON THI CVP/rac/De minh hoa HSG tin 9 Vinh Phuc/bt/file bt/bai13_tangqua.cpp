#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    freopen("quatang.inp","r",stdin);
    freopen("quatang.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        for(int j = i+1;j < n;j++) {
            if(abs(a[i] + a[j]) == k) {
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}


