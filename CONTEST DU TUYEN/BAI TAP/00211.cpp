#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
ll n,k,p,q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> p >> q;
    ll type = (p * q % k == 0 ? k : p * q % k);
    for(int i = 1;i <= n * (n + 1) / 2;i++) {
        ll type2 = i % k; 
        if(type2 == 0) type2 = k;
        if(type == type2) {
            cout << i << ' ' << (i % 2 == 0 ? 2 : 1);
            return 0;
        }
    }
    cout << -1;
    return 0;
}