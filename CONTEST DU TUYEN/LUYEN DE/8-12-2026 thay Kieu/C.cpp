#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,mp[MM],cnt[MM];
ll res = 0;

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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int x; cin >> x;
        
        int d = x;

        vector<int> factor;
        while(d > 1) {
            int p = mp[d];
            factor.push_back(p);
            while(d % p == 0) {
                d /= p;
            }
        }

        int cur_sz = factor.size(), notvalid = 0;
        for(int mask = 1;mask < (1 << cur_sz);mask++) {
            int mul = 1;
            for(int i = 0;i < cur_sz;i++) {
                if(mask >> i & 1)
                    mul *= factor[i];
            }

            int mask_sz = __builtin_popcount(mask);
            if(mask_sz % 2 == 1) notvalid += cnt[mul];
            else notvalid -= cnt[mul];

            cnt[mul]++;
        }

        if(x != 1) {
            int valid = (i - 1) - notvalid;
            res += valid;
        }
        else res += i - 1;
    }
    cout << res;
    return 0;
}