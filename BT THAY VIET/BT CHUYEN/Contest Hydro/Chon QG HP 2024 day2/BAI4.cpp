#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n;

namespace subtask1
{
    ll maxdigit(ll k)
    {
        ll di = 0;
        while(k > 0) {
            di = max(di,k%10);
            k /= 10;
        }
        return di;
    }

    void solve()
    {
        
        int cnt = 0;
        while(n > 0) {
            cnt++;
            n -= maxdigit(n);
        }
        cout << cnt;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    subtask1::solve();
    return 0;   
}