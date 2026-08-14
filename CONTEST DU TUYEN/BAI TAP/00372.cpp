#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,a[MM],prime[MM],ps[MM];

void sieve()
{
    for(int i = 2;i < MM;i++)
        prime[i] = 1;
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; a[i] = prime[ a[i] ];
        ps[i] = ps[i-1] + a[i];
    } 
    ll res = 0;
    int l = 1,r = 1;
    while(l <= n && r <= n) {
        // cout << l << ' ' << r << '\n';
        if(!a[r]) {
            res += r - l + 1;
            r++;
        }
        else {
            r++;
            l = r;
        }
    }
    cout << res;
    return 0;
}