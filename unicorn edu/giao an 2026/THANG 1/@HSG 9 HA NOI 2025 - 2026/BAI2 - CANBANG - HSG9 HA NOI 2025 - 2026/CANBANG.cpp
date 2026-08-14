#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n;
ll k,a[MM];
map<ll,ll> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[ a[i] ] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        cnt += (mp[ a[i] - k ] && mp[ a[i] + k ]);
    }
    cout << cnt;
    return 0;
}