#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

ll palind(ll k)
{
    ll kq = 0;
    while(k > 0) {
        ll tmp = k % 10;
        kq = kq * 10 + tmp;
        k /= 10;
    }
    return kq;
}   

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "palnum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    while(true) {
        ll n1 = palind(n);
        if(n1 == n) {
            cout << n;
            return 0;
        }
        n += n1;
    }
    return 0;
}