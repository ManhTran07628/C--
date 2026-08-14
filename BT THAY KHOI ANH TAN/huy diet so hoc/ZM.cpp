#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll k[16];

ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
    }
    ans = k[1];
    for(int i = 2;i <= n;i++) {
        ans = lcm(ans,k[i]);
    }
    cout << ans;
    return 0;
}