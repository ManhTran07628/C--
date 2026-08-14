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
    int n; cin >> n;
    int cnt = 0;
    while(n--) {
        string a; cin >> a;
        ll check = 0;
        for(auto x:a) {
            check = check + (x - '0');
        }
        cnt += ( (a[ a.size() - 1 ] == '0' || a[ a.size() - 1 ] == '5' ) && check % 5 == 0 ? 1 : 0);
    }
    cout << cnt << '\n';
    return 0;
}