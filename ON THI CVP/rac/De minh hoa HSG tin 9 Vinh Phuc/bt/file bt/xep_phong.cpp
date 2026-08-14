#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
ll a[N];
int main() {
    ll n;
    cin >> n;
    if(n % 3 == 0) {
        cout << 0 << " " << n / 3;
    }
    else if(n % 3 == 1) {
        cout << 2 << " " << n / 3 -1;
    }
    else if(n % 3 == 2) {
        cout << 1 << " " << n / 3;
    }
    return 0;
}



