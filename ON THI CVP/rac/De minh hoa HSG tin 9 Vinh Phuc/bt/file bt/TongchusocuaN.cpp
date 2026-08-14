#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<ll> a;
int main() {
    ll n;
    cin >> n;
    for(ll i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            a.push_back(i);
            if(n / i != i) {
                a.push_back(n/i);
            }
        }
    }
    sort(a.begin(),a.end());
    for(auto c: a) {
        cout << c << endl;
    }
    return 0;
}



