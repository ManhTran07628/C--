#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

ll kttnt(ll k)
{
    ll kq = 0;
    while(k > 0) {
        ll tmp = k % 10;
        kq += tmp;
        k /= 10;
    }
    return a[kq];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SNTDB"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 1;i <= N;i++) a[i] = 1;
    a[0] = a[1] = 0;
    for(int i = 1;i <= sqrt(N);i++) 
        if(a[i])
            for(ll j = i*i;j <= N;j+=i) 
                a[j] = 0;
    ll l,r;
    cin >> l >> r;
    for(ll i = l;i <= r;i++) {
        if(kttnt(i) == 1 && a[i]==1) cout << i << " ";
    }
    return 0;
}