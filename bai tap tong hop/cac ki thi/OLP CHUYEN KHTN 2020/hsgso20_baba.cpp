#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
map<ll,ll> mp,pos;
string s; 

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int type; cin >> type;
    int n = s.size();
    s = ' ' + s;

    if(type == 1) {
        ll res = 0, cur = 0, x = 1;
        mp[0] = 1;
        reverse(s.begin() + 1,s.end());
        for(int i = 1;i <= n;i++) {
            cur = (s[i] - '0') * x + cur; cur %= 33;
            res += mp[cur];
            mp[cur]++;
            x *= 10; x %= 33;
        }
        cout << res;
    }
    else {
        int l = 0, r = 0;
        ll cur = 0, x = 1;
        mp[0] = 0;
        reverse(s.begin() + 1,s.end());
        for(int i = 1;i <= n;i++) {
            cur = (s[i] - '0') * x + cur; cur %= 33;
            x *= 10; x %= 33;
            if(mp.find(cur) == mp.end()) mp[cur] = i;
            else {
                int j = mp[cur];
                if(r - l < i - j) {
                    l = j;
                    r = i;
                }
            }
        }
        for(int i = r;i > l;i--) cout << s[i];
    }
    return 0;
}