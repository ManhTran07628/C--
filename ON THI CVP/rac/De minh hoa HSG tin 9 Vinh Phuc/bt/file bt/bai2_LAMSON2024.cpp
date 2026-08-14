#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N],c[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "uocnto"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 1;i <= N;i++) a[i] = 1; // sang snt
    a[1]=a[0]=0;
    for(int i = 1;i <= sqrt(N);i++) 
        if(a[i])
            for(ll j = i * i;j <= N;j+=i) 
                a[j] = 0;
    for(ll i = 1;i <= N;i++) { // dem uoc
        for(ll j = i;j <= N;j+=i) {
            c[j]++;
        }
    }
    for(int i = 1;i <= N;i++) {
        b[i] = b[i-1] + a[c[i]];
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll a1,b1;
        cin >> a1 >> b1;
        cout << b[b1] - b[a1-1] << '\n'; 
    }
    return 0;
}

