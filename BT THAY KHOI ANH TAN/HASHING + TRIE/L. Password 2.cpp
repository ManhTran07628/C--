#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
const int base = 256;
const int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
int n,ans[MM];
struct Node
{
    vector<ll> str;
} Hash[MM][2];
pair<string,int> t[MM];
ll Pow[MM][2];

ll getHash(int id,int l,int r,int t)
{
    return (Hash[id][t].str[r] - Hash[id][t].str[l - 1] * Pow[r - l + 1][t] % MOD[t] + MOD[t]) % MOD[t];
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "xx"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i < MM;i++) {
        Pow[i][0] = (Pow[i-1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i-1][1] * base) % MOD[1];
    }

    map<ll,ll> mp[MM];
    map<ll,ll> prf_sz,maxval;

    for(int i = 1;i <= n;i++) {
        cin >> t[i].fi;
        t[i].se = i;
    }
    sort(t+1,t+n+1,[] (pair<string,int> a,pair<string,int> b){return a.fi.size() < b.fi.size();});

    for(int i = 1;i <= n;i++) {
        string s = t[i].fi; 
        int sz = s.size();
        s = ' ' + s;
        Hash[i][0].str.resize(sz + 1);
        Hash[i][1].str.resize(sz + 1);

        for(int j = 1;j <= sz;j++) {
            Hash[i][0].str[j] = (Hash[i][0].str[j - 1] * base + s[j] - '0' + 1) % MOD[0];
            Hash[i][1].str[j] = (Hash[i][1].str[j - 1] * base + s[j] - '0' + 1) % MOD[1];
        }
        
        ll h1 = Hash[i][0].str[sz], h2 = Hash[i][1].str[sz];
        ll key = (1ll * h1 << 32) | h2;

        int res = 0;

        unordered_map<int,int> dd;
        for(auto U:prf_sz) {
            int len = U.fi;
            for(int j = len;j <= sz;j++) {
                ll val1 = getHash(i,j - len + 1,j,0), val2 = getHash(i,j - len + 1,j,1);
                ll cur_key = (1ll * val1 << 32) | val2;
                if(mp[len].count(cur_key) && !dd[cur_key]) {
                    res += mp[len][cur_key];
                    dd[cur_key] = 1;
                    // break;
                }
            }
        }

        mp[sz][key]++;
        prf_sz[sz] = 1;

        if(maxval.count(key))
            maxval[key] = max((int) maxval[key], res);
        else
            maxval[key] = res;

        // cout << s << ' ' << res << '\n';

        // cout << res << '\n';
    }

    for(int i = 1;i <= n;i++) {
        string s = t[i].fi;
        int sz = s.size();
        ll h1 = Hash[i][0].str[sz], h2 = Hash[i][1].str[sz];
        ll key = (1ll * h1 << 32) | h2;
        ans[t[i].se] = maxval[key];
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << '\n';
    return 0;
}