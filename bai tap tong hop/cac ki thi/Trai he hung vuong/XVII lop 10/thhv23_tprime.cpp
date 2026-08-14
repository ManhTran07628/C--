#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e6 + 7;
int n,k,a[MM],prime[MM],cost[MM];
vector<int> primes;

void sieve()
{
    fill(prime+1,prime+MM,1);
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
    
    for(int i = 2;i < MM;i++)
        if(prime[i])
            primes.push_back(i);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        int l1 = lower_bound(primes.begin(),primes.end(),a[i]) - primes.begin();
        cost[i] = primes[l1] - a[i];
        if(l1 > 0) cost[i] = min(cost[i],a[i] - primes[l1 - 1]);
        // cout << a[i] << ' ' << cost[i] << '\n';
        a[i] = cost[i] + a[i-1];
    }

    ll res = oo;
    for(int i = k;i <= n;i++) res = min(res,(ll) a[i] - a[i - k]);
    cout << res;
    return 0;
}