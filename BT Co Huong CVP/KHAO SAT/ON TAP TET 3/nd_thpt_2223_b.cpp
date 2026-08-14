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
    #define taskname "THUGON"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    while(cin >> s) {
        int n = s.size();
        s = ' ' + s;
        for(int i = 1;i <= n;) {
            int j = i;
            while(s[j] == s[i] && j <= n) j++;
            string t;
            int k = j - i;
            while(k > 0) {
                char c = k % 10 + '0';
                t = c + t;
                k /= 10;
            }
            if(j - i > 1) cout << t << s[i];
            else cout << s[i];
            i = j;
        }
        cout << '\n';
    }
    return 0;
}