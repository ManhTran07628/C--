#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int prime[MM];

void sieve()
{
    fill(prime+1,prime+MM+1,1);
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "KHACNHAU"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    int x, n;
    cin >> x >> n;
    vector<int> res;
    for (int y = 1; y <= n; y++) {
        if (y != x && (prime[__gcd(x,y)] || y == 1)) {
            res.push_back(y);
        }
    }

    cout << res.size() << '\n';
    for (int v : res) cout << v << ' ';
    return 0;
}