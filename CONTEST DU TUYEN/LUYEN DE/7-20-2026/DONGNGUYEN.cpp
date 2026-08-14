#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,q,a[MM];


namespace subtask1
{
    void solve()
    {
        while(q--) {
            int l,r,x; cin >> l >> r >> x;
            int res = 0;
            for(int i = l;i <= r;i++) 
                if(__gcd(x,a[i]) == 1) res++;
            cout << res << '\n';
        }
    }
}

int mp[MM];

void sieve()
{
    for(ll i = 2;i * i < MM;i++)
        if(mp[i] == 0)
            for(ll j = i;j < MM;j += i)
                if(mp[j] == 0) mp[j] = i;

    for(int i = 2;i < MM;i++)
        if(mp[i] == 0) mp[i] = i;
}

namespace sol
{
    vector<int> pos[MM];
    void solve()
    {
        sieve();
        for(int i = 1;i <= n;i++) { 
            vector<int> vec;
            while(a[i] > 1) {
                int p = mp[ a[i] ];
                vec.push_back(p);
                while(a[i] % p == 0) a[i] /= p;
            } 
            int sz = vec.size();
            for(int mask = 1;mask < (1 << sz);mask++) {
                ll mul = 1;
                for(int i = 0;i < sz;i++)
                    if(mask >> i & 1) mul *= vec[i];

                pos[mul].push_back(i);
            }
        }

        while(q--) {
            int l,r,x; cin >> l >> r >> x;
            vector<int> vec;
            while(x > 1) {
                int p = mp[x];
                vec.push_back(p);
                while(x % p == 0) x /= p;
            }

            ll res = 0, sz = vec.size();
            for(int mask = 1;mask < (1 << sz);mask++) {
                ll mul = 1;
                for(int i = 0;i < sz;i++)
                    if(mask >> i & 1) mul *= vec[i];

                int bitsz = __builtin_popcount(mask);
                
                ll R = upper_bound(pos[mul].begin(),pos[mul].end(),r) - 1 - pos[mul].begin();
                ll L = lower_bound(pos[mul].begin(),pos[mul].end(),l) - pos[mul].begin();

                
                ll cnt = R - L + 1;

                if(bitsz % 2 == 1) res += cnt;
                else res -= cnt;
            }

            cout << r - l + 1 - res << '\n';
        }
    }
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
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sol::solve();
    return 0;
}