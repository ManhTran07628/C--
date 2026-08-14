#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int q;
int mp[MM],cnt[MM];
ll res = 0, sz = 0;

void sieve()
{
    for(ll i = 2;i * i < MM;i++)
        if(mp[i] == 0)
            for(ll j = i * i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;
    for(int i = 2;i < MM;i++)
        if(!mp[i])
            mp[i] = i;
}

void update(set<int> vec,int type)
{
    for(auto mul:vec) {
        if(type == 1) cnt[mul]++;
        else cnt[mul]--;
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
    sieve();
    cin >> q;
    while(q--) {
        char type; cin >> type;
        if(type == '+' || type == '-') {
            int x; cin >> x;

            vector<int> factor;
            // factor.push_back(1);
            
            int d = x;
            while(d > 1) {
                int p = mp[d];
                factor.push_back(p);
                while(d % p == 0) d /= p;
            }

            ll notvalid = 0;

            for(int mask = 1;mask < (1 << factor.size());mask++) {
                vector<int> valid;  
                ll mul = 1;

                for(int i = 0;i < factor.size();i++) {
                    if(mask >> i & 1) 
                        mul *= factor[i];
                    
                }

                int mask_sz = __builtin_popcount(mask);
                if(mask_sz % 2 == 0) notvalid -= cnt[mul];
                else notvalid += cnt[mul];

                if(type == '+') cnt[mul]++;
                else cnt[mul]--;
            }

            if(x > 1) {
                if(type == '+') {
                    ll valid = sz - notvalid;
                    res += valid;
                    sz++;
                }
                else {
                    ll valid = sz - notvalid;
                    res -= valid;
                    sz--;
                }
            }
            else {
                if(type == '+') {
                    res += sz;
                    sz++;
                }
                else {
                    sz--;
                    res -= sz;
                }
            }
        }
        else {
            cout << res << '\n';
        }
    }
    return 0;
}