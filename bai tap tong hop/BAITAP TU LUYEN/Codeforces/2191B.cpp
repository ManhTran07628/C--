#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int,int> mp;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            mp[ a[i] ]++;
        }
        if(!mp[0]) {
            cout << "NO" << '\n';
            continue;
        }
        if(mp[0] >= 2 && !mp[1]) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';

    }
    return 0;
}