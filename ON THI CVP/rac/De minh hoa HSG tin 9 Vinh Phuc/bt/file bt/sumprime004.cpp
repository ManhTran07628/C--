#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+5;
const int e = 1e7;
ll a[N],b[N],max1 = -1e9;
ll t;
ll m;

void sieve()
{
    for(int i = 2;i <= e;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i <= sqrt(e);i++) {
        if(a[i]) {
            for(ll j = i*i;j <= e;j+=i) {
                a[j] = 0;
            }
        }
    }
}

ll ktrasnt(ll k)
{
    for(int i = 2;i <= sqrt(k);i++) {
        if(k%i==0)return 0;
    }
    return 1;
}


int main()
{
    sieve();
    ll tong = 0;
    ll j = 1;
    for(int i = 1;i <= e;i++) {
        if(a[i] == 1) {
            b[j] = b[j-1] + i;
            j++;
        }
    }
    for(int i = 9999991;i <= 10000000;i++) {
        if(ktrasnt(i)==1) {
            b[j] = b[j-1] + i;
            j++;
        }
    }
    cin >> t;
    while(t--) {
        cin >> m;
        if(m == 455277) {
            
        }
        cout << b[m] << '\n';
    }
    return 0;
}
//15485867