#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll prime[N],f[N];

void sieve()
{
    fill(prime,prime+N,1);
    prime[1] = 0;
    for(int i = 1;i <= sqrt(N);i++)
        if(prime[i])
            for(ll j =i*i;j <= N;j+=i) 
                prime[j] = 0;
}

ll check(ll k)
{
    ll sum = 0,pr = 1;
    ll k1 = k;
    while(k1 > 0) {
        sum += k1 % 10;
        k1 /= 10;
    }
    while(k > 0) {
        pr *= (k%10);
        k /= 10;
    }
    if(sum % 2 == 0 && pr != 0) return 1;
    else return 0;
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
    sieve();
    ll a,b;
    cin >> a >> b;
    for(int i = a;i <= b;i++) {
        if(prime[i] && check(i)) cout << i << " ";
    }
    return 0;
}