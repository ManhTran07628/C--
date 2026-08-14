#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
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
    ll n,k,dem = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        if(a[i] == 1 && a[i+k] == 1 && i+k <= n) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}