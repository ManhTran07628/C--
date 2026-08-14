#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
ll n,a[MM],pownum[MM];
vector<int> adj[MM];

void sieve()
{
    for(ll i = 1;i * i < MM;i++)
        for(ll j = 1;i * i * j < MM;j++) {
            pownum[i * i * j] = j;
        }
}

namespace brute
{
    bool ktscp(ll k)
    {
        ll sqrtk = sqrt(k);
        if(sqrtk * sqrtk == k) return 1;
        return 0;
    }

    void solve()
    {
        int res = 0;
        for(int i = 1;i <= n;i++) 
            for(int j = i+1;j <= n;j++) 
                for(int k = j+1;k <= n;k++) {
                    if(ktscp(a[i] * a[j]) && ktscp(a[i] * a[k]) && ktscp(a[k] * a[j])) res++;
                }

        cout << res;
    }
}

namespace sol
{
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            a[i] = pownum[ a[i] ];
            adj[ a[i] ].push_back(i);
        }

        ll res = 0;
        for(int i = 1;i < MM;i++) {
            ll cnt = adj[i].size();
            res += cnt * (cnt - 1) * (cnt - 2) / 6;
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if(n <= 100) brute::solve();
    else sol::solve();
    return 0;
}
