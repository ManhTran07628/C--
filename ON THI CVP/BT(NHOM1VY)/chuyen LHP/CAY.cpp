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
    ll n,m;
    cin >> n >> m;
    ll x = __gcd(n,m);
    cout << x << '\n' << n/x << ' ' << m/x;
    return 0;
}