#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int MOD = 1e9 + 7;
ll a[MM],q,n,b[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i]; 
        a[i] %= MOD;
        b[i] %= MOD;
    }
    reverse(b+1,b+n+1);
    int cur = 0;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            ll x; cin >> x; x %= MOD;
            for(int i = 1;i <= n;i++) {
                a[i] += x;
                b[i] += x;
                a[i] %= MOD;
                b[i] %= MOD;
            }
        }
        if(type == 2) {
            ll x; cin >> x;
            for(int i = 1;i <= n;i++) {
                a[i] = (a[i] % MOD * x % MOD) % MOD;
                b[i] = (b[i] % MOD * x % MOD) % MOD;
            }
        }
        if(type == 3) {
            cur++; cur %= 2;
        }
        for(int i = 1;i <= n;i++) {
            cout << (cur == 0 ? a[i] : b[i]) % MOD << ' ';
        }
        cout << '\n';
    }
    return 0;
}