#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+5;
ll a[N],b[N];

ll demchuso(ll k)
{
    ll tong = 0;
    while(k > 0) {
        ll tmp = k % 10;
        tong += tmp;
        k /= 10;
    }
    return tong;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PASSWORD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll l,r;
    for(int i = 1;i <= N;i++) a[i] = 1;
    a[0]=a[1]=0;
    for(int i = 2;i <= sqrt(N);i++)
        if(a[i])
            for(ll j = i*i;j <= N;j+=i) 
                a[j] = 0;
    cin >> l >> r;
    for(int i = l;i <= r;i++) {
        if(a[i] == 1) {
            ll ans = demchuso(i);
            b[i] = a[ans];
        }
    }
    for(int i = l;i <= r;i++) {
        if(b[i] == 1) cout << i << " ";
    }
    return 0;
}