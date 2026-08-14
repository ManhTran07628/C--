#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],f[N];

ll ktsnt(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++)
        if(k % i == 0) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "knto"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,dem = 0;
    cin >> n;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            if(ktsnt(i) == 0) dem++;
            if(n / i != i) 
                if(ktsnt(n/i) == 0) dem++;
        }
    }
    cout << dem;
    return 0;
}