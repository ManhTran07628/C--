#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll l,r,a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r >> a;
    ll k = (r - l) / a;
    ll ans = k * (r - l + 1) - a * k * (k + 1) / 2;
    cout << ans;
    return 0;
}