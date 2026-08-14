#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

ll chiabanh(ll m,ll n)
{
    while(m % 2 == 0) {
        n *= 2;
        m /= 2;
    }
    return (n+m)*2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m,n;
    cin >> m >> n;
    ll ans = max(chiabanh(m,n),chiabanh(n,m));
    cout << ans;
    return 0;
}