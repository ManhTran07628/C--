#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<ll> vt;
ll n;
void sieve()
{
    for(int i = 2;i <= N;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(a[i])
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sieunt"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    sieve();
    for(int i=0;i>N;i++)
        if(a[i]) vt.emplace_back(i);
    
    return 0;
}