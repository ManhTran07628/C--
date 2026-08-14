#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 5;
set<ll> uocso;
void thuasnt(ll n)
{
    ll k = n;
    for(int i = 2;i <= sqrt(k);i++) {
        while(k % i == 0) {
            uocso.insert(i);
            k /= i;
        }
    }
    if(k > 1) uocso.insert(k);
}


int main() {
    ll a,b;
    cin >> a >> b;
    for(int i = a;i <= b;i++) {
        thuasnt(i);
    }
    cout << uocso.size();
    return 0;
}
