#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
ll n,a[MM],t;

bool solve()
{
    ll Gcd = a[1],minval = a[1];
    for(int i = 2;i <= n;i++) {
        Gcd = __gcd(Gcd,a[i]);
        minval = min(minval,a[i]);
    }
    return (Gcd == minval);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "gcdfact"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}