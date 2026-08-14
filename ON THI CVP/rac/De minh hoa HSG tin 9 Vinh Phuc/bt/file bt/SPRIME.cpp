#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll tmas = 1e6;
ll tongcs(ll k)
{
    ll tong = 0;
    while(k > 0) {
        ll tmp = k % 10;
        tong += tmp;
        k/=10;
    }
    if(tong < 2) return 0;
    for(int i = 2;i <= sqrt(tong);i++) {
        if(tong % i == 0) return 0;
    }
    return 1;
}
ll ktsnt(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++) {
        if(k % i == 0) return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SPRIME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 1;i <= 1000001;i++) {
        a[i] = a[i-1] + a[i];
        if(ktsnt(i) == 1 && tongcs(i) == 1) {
            a[i]++;           
        }
    }
    ll t;
    cin >> t;
    while(t--) {
        ll l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}