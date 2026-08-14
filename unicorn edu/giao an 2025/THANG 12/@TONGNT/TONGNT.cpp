#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e7+7;
ll prime[MAXN + 5];
void sieve()
{
    for(int i = 2;i < MAXN;i++) prime[i] = 1;
    
    for(ll i = 2;i * i < MAXN;i++)
        if(prime[i])
            for(ll j = i * i;j < MAXN;j+=i)
                prime[j] = 0;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        ll x; cin >> x;
        if(prime[x]) res += x;
    }
    cout << res;
    return 0;
}