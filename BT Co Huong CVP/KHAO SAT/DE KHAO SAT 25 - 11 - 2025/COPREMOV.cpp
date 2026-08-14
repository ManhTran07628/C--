#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MS = 1e7+7;
int t,n,mp[MS],a[MS];
int cntdiv[MS];
bool prime[MS];
vector<int> primes;

void sieve()
{
    for(int i = 2;i < MS;i++) prime[i] = 1;

    for(ll i = 2;i * i < MS;i++)
        if(prime[i])
            for(ll j = i * i;j < MS;j+=i)
                prime[j] = 0;

    for(int i = 2;i < MS;i++)
        if(prime[i])
            primes.push_back(i);
}

void min_prime()
{
    for(ll i = 2;i < MS;i++)
        if(mp[i] == 0)
            for(ll j = i;j < MS;j += i)
                if(mp[j] == 0)
                    mp[j] = i;

    for(int i = 2;i < MS;i++)
        if(mp[i] == 0)
            mp[i] = i;
}


void solve()
{
    for(auto p:primes) cntdiv[p] = 0;
    int lim = 1;
    for(int i = 1;i <= n;i++) {
        lim = max(lim,a[i]);
        int k = a[i];

        while(k > 1) {
            int p = mp[ k ];
            cntdiv[p]++;

            while(k % p == 0) k /= p;

        }
    }

    int ans = 0;
    for(auto p:primes) {
        if(p > lim) break;
        if(cntdiv[p] > ans) ans = cntdiv[p];
        ans = max(ans,cntdiv[p]);
    }
    cout << n - ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "COPREMOV"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    min_prime();
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];

        solve();
    }

    return 0;
}
