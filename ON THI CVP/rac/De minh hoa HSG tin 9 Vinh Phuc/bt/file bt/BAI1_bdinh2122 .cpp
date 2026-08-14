#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "bauoc"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= N;i++) a[i] = 1;
    a[0] = a[1] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(a[i]) 
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
    ll dem = 0;
    for(ll i = 1;i <= sqrt(n);i++) {
        if(a[i] == 1 && i * i <= n) dem++;
    }
    cout << dem;
    return 0;
}