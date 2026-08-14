#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

ll slsh(ll k)
{
    ll kq = 0;
    while(k > 0) {
        kq++;
        k /= 10;
    }
    return kq;
}

int main()
{
    ll n;
    cin >> n;
    ll kq = 0,sc = 10,d = 1,ssh = slsh(n),sd = 1;
    for(int i = 1;i < ssh;i++) {
        kq += (sc-1-sd+1)*d;
        sc *= 10;
        sd *= 10;
        d++;
    }
    kq += (n-sc/10+1)*d;
    cout << kq;
    return 0;
}