#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const ll MOD = 1e9 + 7;
ll fact[1000];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "CHUPANH"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n1, n2;
    cin >> n1 >> n2;

    // nếu không thể xen kẽ
    if (abs(n1 - n2) > 1) {
        cout << 0;
        return 0;
    }

    // tính giai thừa
    fact[0] = 1;
    for (int i = 1; i <= 200; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }

    ll res = fact[n1] * fact[n2] % MOD;

    if (n1 == n2) res = res * 2 % MOD;

    cout << res;
    return 0;
}