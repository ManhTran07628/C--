#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 7e4 + 7;
int n,q,a[MM],mp[MM],prime[MM];
ll Hash[MM],pfs[MM],v[MM];
vector<int> primes;
void sieve() {
    for(int i = 2;i < MM;i++) {
        prime[i] = 1;
    }

    for(int i = 2;i < MM;i++) {
        if(prime[i]) {
            mp[i] = i;
            for(int j = i * 2;j < MM;j += i) {
                prime[j] = 0;
                if(mp[j] == 0) mp[j] = i;
            }
        }
    }

    for(int i = 2; i < MM; i++)
        if(prime[i]) primes.push_back(i);
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
    srand(time(NULL));
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    for(auto p:primes) {
        Hash[p] = rd(1,(ll)1e18);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        int x = a[i];
        while(x > 1) {
            int p = mp[x];
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            if(cnt % 2 == 1) 
                v[i] ^= Hash[p];
        }
        pfs[i] = pfs[i-1] ^ v[i];
        
    }

    while(q--) {
        int l,r; cin >> l >> r;
        bool ok = ((pfs[r] ^ pfs[l-1]) == 0);
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}