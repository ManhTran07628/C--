#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll frac[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    frac[0] = 1;
    for(ll i = 1;i < 100;i++) {
        for(int j = 0;j < i;j++)
            frac[i] += (frac[j] * frac[i - j - 1]);
    }
    cout << frac[n];
    return 0;
}