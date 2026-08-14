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
    ll n;
    cin >> n;
    n *= 2;
    ll sd = int(sqrt(n));
    ll ans = (sd+1)*sd/2;
    if(ans == n/2) cout << sd;
    else cout << "NO";
    return 0;
}