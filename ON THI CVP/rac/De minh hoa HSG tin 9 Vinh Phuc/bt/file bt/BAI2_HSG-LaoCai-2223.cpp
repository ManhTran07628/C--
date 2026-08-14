#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

ll palindrome(ll k)
{
    ll k1 = k,kq = 0;
    while(k1 > 0) {
        ll tmp = k1 % 10;
        kq = kq * 10 + tmp;
        k1/=10;
    }
    if(kq == k) return 1;
    else return 0;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SDXDEP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 2;i <= N;i++) {
        if(a[i] == 0) {
            for(ll j = i;j <= N;j+=i) {
                a[j]++;
            }
        }
    }
    ll a1,b,dem = 0;
    cin >> a1 >> b;
    for(int i = a1;i <= b;i++) {
        if(palindrome(i) == 1) {
            if(a[i] >= 3) dem++;
        }
    }
    cout << dem;
    return 0;
}