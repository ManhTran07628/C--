#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
ll n,k;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(k == 0) {
        cout << n;
        return 0;
    }

    if( (n % 10) % 2 == 1 ) {
        k--;
        n += n % 10;
    }

    if(n % 10 == 0) {
        cout << n;
        return 0;
    }

    ll res = n + (k / 4) * 20;
    k %= 4;
    for(int i = 0;i < k;i++) {
        res += (res % 10);
    }
    cout << res;
    return 0;
}