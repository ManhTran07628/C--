#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,prime[MM];

void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
}

bool check(ll k)
{
    if(!prime[k]) return 0;
    ll res = 0;
    while(k > 0) {
        res += k % 10;
        k /= 10;
    }
    return prime[res];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n; cin >> n;
    int res = 0;
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        res += check(a);
    }
    cout << res;
        
    return 0;
}