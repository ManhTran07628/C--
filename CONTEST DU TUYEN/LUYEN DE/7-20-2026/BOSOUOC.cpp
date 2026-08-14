#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n;
struct QR{char type; int x;} qr[MM];

namespace subtask1
{
    vector<int> vec;
    void solve()
    {
        ll res = 0, sz = 0;
        for(int t = 1;t <= n;t++) {
            char type = qr[t].type;
            int x = qr[t].x;
            if(type == '+') {
                vec.push_back(x);
                for(int i = 0;i < vec.size() - 1;i++) {
                    if(__gcd(vec[i],x) == 1) res++;
                }
            }
            else {
                for(int i = 0;i < vec.size();i++) {
                    if(vec[i] == x) {
                        vec.erase(vec.begin() + i);
                        break;
                    }
                }

                for(int i = 0;i < vec.size();i++) {
                    if(__gcd(vec[i],x) == 1) {
                        res--;
                    }
                }
                sz--;
            }
            cout << res << '\n';
        }
    }
}

namespace subtask2
{
    int cnt[MM];
    void solve()
    {
        ll res = 0, sz = 0;
        for(int t = 1;t <= n;t++) {
            char type = qr[t].type;
            int x = qr[t].x;
            if(type == '+') {
                if(x == 1) res += sz;
                else res += (sz - cnt[x]);
                sz++;
                cnt[x]++;
            }
            else { 
                if(x == 1) res -= sz;
                else res -= (sz - cnt[x]);
                sz--;
                cnt[x]--;
            }
            cout << res << '\n';
        }
    }
}

int prime[MM],mp[MM];

void sieve()
{
    fill(prime+1,prime+MM,1);
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;

    for(ll i = 2;i < MM;i++)
        if(mp[i] == 0)
            for(ll j = i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;

    for(int i = 2;i < MM;i++)
        if(mp[i] == 0) mp[i] = i;
}

namespace subtask3
{
    ll adj[MM];

    bool check()
    {
        for(int t = 1;t <= n;t++) {
            if(qr[t].type == '-') return 0;
        }
        return 1;
    }

    void solve()
    {
        sieve();

        ll res = 0, sz = 0;
        for(int t = 1;t <= n;t++) {
            int type = qr[t].type;
            int x = qr[t].x;
            vector<int> factor;
            
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
                if(mask_sz % 2 == 0) notvalid -= adj[mul];
                else notvalid += adj[mul];

                if(type == '+') adj[mul]++;
                else adj[mul]--;
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

            cout << res << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BOSOUOC"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> qr[i].type >> qr[i].x;
    subtask3::solve();
    return 0;
}
