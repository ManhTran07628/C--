#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 7e4 + 7;
int n,q,a[MM],mp[MM],prime[MM];
ll hval[MM],ps[MM];
vector<int> primes;
void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;

    for(ll i = 2;i < MM;i++) {
        if(mp[i] == 0)
            for(ll j = i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;

        if(prime[i]) {
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
        }
    }

    for(int i = 2;i < MM;i++) {
        if(prime[i]) primes.push_back(i);
        if(!mp[i]) mp[i] = i;
    }
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rd(ll l,ll r)
{
    return rng() % (r - l + 1) + l;
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
    srand(time(NULL));
    sieve();
    for(int i = 2;i <= 10;i++) cout << i << ' ' << mp[i] << '\n';
    return 0;
    for(auto x:primes) hval[x] = rd(1,1e18);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        int x = a[i];
        ll cur_v = 0;
        while(x > 1) {
            int p = mp[x];
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            if(cnt % 2 == 1) cur_v = cur_v ^ hval[p];
        } 
        ps[i] = ps[i-1] ^ cur_v;
    }
    // cout << 1;
    while(q--) {
        int l,r; cin >> l >> r;
        if((ps[r] ^ ps[l-1]) == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}