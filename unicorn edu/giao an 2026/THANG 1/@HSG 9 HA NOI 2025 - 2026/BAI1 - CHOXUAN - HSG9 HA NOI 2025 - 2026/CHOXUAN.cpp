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
    ll n,k; cin >> n >> k;
    if(k * 7 > n) cout << -1;
    else cout << n - k * 7;
    return 0;   
}