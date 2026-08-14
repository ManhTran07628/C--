#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "COUNTPRI"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 2;i <= N;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(a[i])
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
    for(int i = 1;i <= N;i++) {
        b[i] = b[i-1] + a[i];
    }
    ll t;
    cin >> t;
    while(t--) {
        ll l,r;
        cin >> l >> r;
        cout << b[r] - b[l-1] << '\n';
    }
   return 0;
}