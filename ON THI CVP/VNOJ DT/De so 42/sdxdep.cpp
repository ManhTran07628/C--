#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+1;
ll f[N],p[N],prime[N];



void sieve()
{
    for(int i = 1;i <= N;i++) prime[i] = 1;
    prime[1] = prime[0] = 0;
    for(int i = 2;i*i <= N;i++) 
        if(prime[i])
            for(ll j = i*2;j <= N;j+=i) {
                prime[j] = 0;
            }


    for(int i = 2;i <= N;i++) {
        if(prime[i])
            for(ll j = i;j <= N;j+=i) {
                f[j]++;
            }
    }

}
ll check(ll k)
{
    ll tmp = 0;
    ll k1 = k;
    while(k1 > 0) {
        tmp = tmp * 10 + (k1%10);
        k1 /= 10;
    }
    return tmp == k;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sdxdep"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    ll a,b;
    cin >> a >> b;
    ll cnt = 0;
    for(int i = a;i <= b;i++) {
        if(check(i) && f[i] >= 3) cnt++;
    }
    cout << cnt;
    return 0;
}