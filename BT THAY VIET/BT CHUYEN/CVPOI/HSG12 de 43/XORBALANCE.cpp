#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,a[MM],cur = 0;
map<int,int> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        cur ^= a[i];
        mp[ a[i] ]++;
    }
    int q; cin >> q;
    while(q--) {
        int type,i,v; cin >> type;
        if(type == 1) {
            cin >> i >> v; i++;
            mp[ a[i] ]--;
            cur ^= a[i] ^ v;
            a[i] = v;
            mp[ a[i] ]++;
        }
        else cout << mp[cur] << '\n';
    }
    return 0;
}