#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll a[N];

void sieve()
{
    for(int i = 1;i <= N;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(a[i])
            for(int j = i*i;j <= N;j+=i) 
                a[j] = 0;
}

ll tcs(ll k)
{
    ll ans = 0;
    while(k > 0) {
        ans += k % 10;
        k /= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "password"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    ll l,r;
    cin >> l >> r;
    for(int i = l;i <= r;i++) {
        if(a[tcs(i)] && a[i]) cout << i << " ";
    }

    return 0;
}