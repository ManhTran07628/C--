#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<ll> b;
ll kt(ll k,ll i)
{
    ll dem = 0;
    while(k > 0) {
        dem++;
        k /= 10;
    }
    if(dem == i) return 1;
    return 0;
}
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
    ll d,n;
    cin >> d >> n;
    for(int i = 1;i <= N;i++) a[i] = 0;
    a[1]=a[0]=0;
    for(int i = 1;i <= sqrt(N);i++) 
        if(a[i])
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
    for(int i = 1;i <= 100001;i++) {
        
    }
    return 0;
}   