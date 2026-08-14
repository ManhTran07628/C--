#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    n--; m--;
    ll steps = ceil( (double) min(n,m) / k );
    ll st = min(n,m);

    n -= st; m -= st;
    steps += ceil ( (double) n / k) + ceil( (double) m / k);
    cout << steps;
    return 0;
}