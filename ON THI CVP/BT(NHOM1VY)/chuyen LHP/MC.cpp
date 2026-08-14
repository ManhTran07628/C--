#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,p;
    cin >> n >> p;
    ll ans = n*p - (n/10)*p;
    while(ans / p + (ans/10/p) != n) ans += p;
    cout << ans;
    return 0;
}
