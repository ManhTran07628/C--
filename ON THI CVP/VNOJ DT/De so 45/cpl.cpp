#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
ll tmp = 1e9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cpl"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,sl = 0,tong = 0;
    cin >> n;
    for(ll i = 1;i <= sqrt(n);i++) {
        if(i % 2 != 0) {
            sl++;
            tong += i*i;
        }
    }
    cout << sl << "\n" << tong;
    return 0;
}