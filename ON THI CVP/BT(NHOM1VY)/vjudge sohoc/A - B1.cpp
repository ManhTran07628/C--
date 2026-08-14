#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

ll tsnt(ll n,ll k)
{
    ll ans = 0;
    ll k1 = k;
    while(k <= n) {
        ans += n / k;
        k *= k1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << tsnt(n,5) << '\n';
    }
    return 0;
}