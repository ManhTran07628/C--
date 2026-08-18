#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
string s;
int q,n;
ll qr[MM];

namespace subtask1
{
    void solve()
    {
        vector<string> vec;
        for(int len = 1;len <= n;len++) {
            for(int i = 1;i + len - 1 <= n;i++) {
                string k = s.substr(i,len);
                // cout << k << '\n';
                vec.push_back(k);
            }
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());

        // for(auto e:vec) cout << e << '\n';
        // cout << vec.size() << '\n';

        for(int t = 1;t <= q;t++) {
            ll k = qr[t];
            if(k > (ll) vec.size()) {
                cout << -1 << '\n';
                continue;
            }
            cout << vec[k - 1] << '\n';
        }
    }
}

namespace subtask2
{
    bool checksub2()
    {
        for(int i = 1;i < n;i++)
            if(s[i] != s[i + 1]) return 0;
        return 1;
    }
    void solve()
    {
        for(int t = 1;t <= q;t++) {
            ll k = qr[t];
            if(k > n) continue;
            for(int i = 1;i <= k;i++) cout << s[i];
            cout << '\n';
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
    cin >> s >> q;
    n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= q;i++) cin >> qr[i];
    // if(subtask2::checksub2()) subtask2::solve();
    subtask1::solve();
    return 0;
}