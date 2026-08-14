#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


bool kt(ll k)
{
    while(k > 0) {
        ll tmp = k%10;
        if(tmp != 2 && tmp != 7 && tmp != 0) return 0;
        k /= 10;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll tmp = 1e10;
    ll ans = n;
    while(1) {
        if(kt(ans) && ans % n == 0) {
            cout << ans;
            return 0;
        }
        ans += n;
    }
    return 0;
}