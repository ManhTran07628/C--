#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e5 + 7;
const int MOD[] = {(int) 1e9 + 123,(int) 1e9 + 2277};
const int base = 256;
int n,k;
vector<pair<string,pair<ll,int>>> s;
unordered_map<ll,int> mp;
string st[MM];

bool cmp(pair<string,pair<ll,int>> x, pair<string,pair<ll,int>> y)
{
    int c1 = mp[ x.se.fi ], c2 = mp[ y.se.fi ];
    if(c1 != c2) return c1 > c2;
    return x.se.se > y.se.se;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "gratitude"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }   
    cin >> n >> k;
    cin.ignore();
    for(int i = 1;i <= 3 * n;i++) {
        getline(cin,st[i]);
    }

    for(int i = 3 * n;i >= 1;i--) {
        string t = st[i];
        ll h1 = 0, h2 = 0;
        for(auto c:t) {
            h1 = (h1 * base + c - 'a' + 1 + MOD[0]) % MOD[0];
            h2 = (h2 * base + c - 'a' + 1 + MOD[1]) % MOD[1];
        }

        ll key = (h1 << 32) | h2;
        if(mp.find(key) == mp.end()) {
            s.push_back({t,{key,i}});
        }
        mp[key]++;
    }

    n *= 3;
    sort(s.begin(),s.end(),cmp);
    for(int i = 0;i < min(k,(int) s.size());i++) cout << s[i].fi << '\n';
    return 0;
}