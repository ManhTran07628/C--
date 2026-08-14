#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5;
const int base = 256;
const int MOD = 1e9 + 2277;
string s;
vector<ll> hashQ;
map<ll,ll> cnt;
int q;
ll qr[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> q;
    for(int i = 0;i < q;i++) {
        string t; cin >> t;
        ll Hash = 0;
        for(int j = 0;j < t.size();j++) {
            Hash = (Hash * base + t[j] - '0' + 1) % MOD;
        }
        hashQ.push_back(Hash);
    }
    cnt[0] = 1;

    int n = s.size();
    s = ' ' + s; ll Hash = 0, ss = 1;
    for(int i = 1;i <= n;i++) {
        Hash = (Hash * base + s[i] - '0' + 1) % MOD;
        cout << Hash << ": ";
        for(int j = 0;j < hashQ.size();j++) {
            ll k = ((Hash - ss * hashQ[j]) % MOD + MOD) % MOD;
            cout << k << ' ';
            qr[j] += cnt[k];
        }
        ss = (ss * 10) % MOD;
        cout << '\n';
        cnt[Hash]++; 
    }
    for(int i = 0;i < q;i++) cout << qr[i] << '\n';
    return 0;
}