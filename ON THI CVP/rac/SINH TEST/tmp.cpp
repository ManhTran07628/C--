#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e6 + 7;
int n,d,a[MM];
int mp[MM];

void sieve()
{
    for(ll i = 2;i * i < MM;i++)
        if(mp[i] == 0)
            for(ll j = i * i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;
    for(int i = 2;i < MM;i++)
        if(mp[i] == 0)
            mp[i] = i;
}

namespace subtask1
{
    void solve()
    {
        int res = 0;
        for(int i = 1;i <= n;i++) {

            for(int j = i + 1;j <= n;j++) {

                map<int,int> cnt;
                int x = a[i];
                while(x > 1) {
                    int p = mp[x];
                    while(x % p == 0) {
                        cnt[p]++;
                        x /= p;
                    }
                }

                x = a[j];
                while(x > 1) {
                    int p = mp[x];
                    while(x % p == 0) {
                        cnt[p]++;
                        x /= p;
                    }
                }

                bool ok = 1;

                for(auto p:cnt) {
                    if(p.se % d != 0) {ok = 0; break;}
                }

                res += ok;
            }

        }

        cout << res;
    }
}

namespace subtask2
{
    ll valdiv[MM],cnt[MM];
    void solve()
    {
        for(ll i = 1;i * i < MM;i++) {
            for(ll j = 1;j * i * i < MM;j++) {
                valdiv[j * i * i] = j;
            }
        }

        ll res = 0;
        for(int i = 1;i <= n;i++) {
            res += cnt[ valdiv[ a[i] ] ];
            cnt[ valdiv[ a[i] ] ]++;
        }
        cout << res;
    }
}

namespace sol
{
    pii valdiv[MM];
    ll cnt[MM];

    ll binpow(ll a,ll b)
    {
        if(b == 0) return 1;
        ll x = binpow(a,b / 2);
        if(b % 2 == 1) return x * x * a;
        return x * x;
    }

    void solve()
    {
        // for(ll i = 1;binpow(i,d) < MM;i++) {
            // ll x = binpow(i,d);
            ll x = 1;
            for(ll j = 1;j * x < MM - 1;j++) {

                ll k = j;

                bool ok = 1;
                ll add = 1;

                while(k > 1) {
                    int p = mp[k];
                    int cur_factor = 0;
                    while(k % p == 0) {
                        cur_factor++;
                        k /= p;
                    }
                    if(cur_factor <= d) {
                        cout << j << ": " << p << ' ' << cur_factor << '\n';
                    }
                }

                // if(!ok) {
                //     valdiv[x * j] = {-1,-1};
                // }
                // else {
                //     valdiv[x * j] = {j,add};
                //     if(x * j <= 8) {
                //         cout << x << ' ' << j << ' ' << add << '\n';
                //     }
                // }
            }
        // }


        // ll res = 0;
        // for(int i = 1;i <= n;i++) {
        //     if(valdiv[ a[i] ].fi == -1) continue;
        //     res += cnt[ valdiv[ a[i] ].se ];
        //     cnt[ valdiv[ a[i] ].fi ]++;
        // }

        // cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    cin >> n >> d;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // if(d == 2) subtask2::solve();
    // else subtask1::solve();
    sol::solve();
    return 0;
}