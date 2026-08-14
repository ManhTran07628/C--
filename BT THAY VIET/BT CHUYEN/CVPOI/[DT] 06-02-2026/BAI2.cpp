#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string cur = "", res = "";
    for(auto c:s) {
        if(isdigit(c)) {
            if(cur.empty() && c == '0') continue;
            cur.push_back(c);
        }
        else {
            if(cur.size() > res.size() || cur > res) res = cur;
            cur = "";
        }
    }
    if(cur.size() > res.size() || cur > res) res = cur;
    if(res == "") cout << -1;
    else cout << res;
    return 0;   
}