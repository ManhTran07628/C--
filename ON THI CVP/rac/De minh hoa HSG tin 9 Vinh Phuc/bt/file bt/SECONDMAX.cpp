#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a+1,a+1+n);
    if(a[1] == a[n]) {
        cout << 0;
        return 0;
    }
    ll gt = a[n];
    for(int i = n;i >= 1;i--) {
        if(gt > a[i]) {
            gt = a[i];
            break;
        }
    }
    cout << gt << endl;
    for(int i = 1;i <= n;i++) {
        if(b[i] == gt) {
            cout << i << " ";
        }
    }
    return 0;
}



