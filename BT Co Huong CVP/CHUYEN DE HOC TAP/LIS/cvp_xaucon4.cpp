#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s,t; cin >> s >> t;
    int res = 0;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i = 1;i <= m;i++) {
        int maxx = 0;
        int k = i;
        for(int j = 1;j <= n;j++) {
            if(t[k] == s[j]) {
                maxx++;
                k++;
            }
            else if(t[k] != s[j] || k > m) {
                res = max(res,maxx);
                maxx = 0;
                k = i;
            }
        }
        res = max(res,maxx);
    }
    cout << res;
    return 0;
}