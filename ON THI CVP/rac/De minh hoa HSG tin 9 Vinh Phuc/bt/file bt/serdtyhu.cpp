#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;

ll snt(ll k)
{
    for(int i = 2;i <= sqrt(k);i++) {
        if(k%i==0) return 0;
    }
    return 1;
}

ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    ll lt = 0;
    for(int i = 2;i <= sqrt(n);i++) {
        if(snt(i)==1) {
            lt = i;
        }
    }
    ll tmp = n / lt;
    while(!snt(tmp)) tmp--;
    cout << tmp * lt;
    return 0;
}
