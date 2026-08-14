#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
ll a[N];


int main() {
    ll t = 3;
    while(t--) {
        ll k;
        cin >> k;
        if(k % 5 == 0)k--;
        if(k % 2 == 0)k--;
        ll solanlap = k / 10;
        ll solandu = k % 10;
        ll kq = 1;
        if(solanlap % 2 == 0) {
            kq = 1;
        }
        else {
            kq = 9;
        }
        for(int i = 1;i <= solandu;i++) {
            if(i % 2 != 0 && i % 5 != 0) {
                kq *= i % 10;
            }
        }
        cout << kq % 10<< endl;
    }
    return 0;
}

