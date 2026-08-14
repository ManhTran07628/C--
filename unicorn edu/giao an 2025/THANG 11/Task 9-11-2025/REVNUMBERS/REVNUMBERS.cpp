#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;

// q <= 5000, |q_i| <= 5000
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        cout << s << '\n';
    }
    return 0;
}