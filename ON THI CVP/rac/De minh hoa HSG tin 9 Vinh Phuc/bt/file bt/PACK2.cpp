#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll i = 1,j = n;
    ll dem = 0;
    while(i <= j) {
        if(a[i] + a[j] <= m) {
            i++;
            j--;
            dem++;
        }
        else {
            j--;
            dem++;
        }
    }
    cout << dem;
    return 0;
}





