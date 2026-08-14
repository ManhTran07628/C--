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
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s; cin >> s;
    int cnt = 0;
    int n = s.size(); s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        if(s[i] == 'v') {
            if(i + 5 - 1 > n) break;

            string t = s.substr(i,5);
            if(t == "virus") cnt++;
        }
    }

    cout << cnt;
    return 0;
}