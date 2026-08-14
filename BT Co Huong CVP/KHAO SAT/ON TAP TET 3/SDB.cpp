#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int prime[MM];
vector<ll> b;

void sieve()
{
    fill(prime+1,prime+MM,1);
    for(int i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "SDB"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    for(int i = 2;i < MM;i++)
        if(prime[i])
            b.push_back(1ll * i * i);
    int n; cin >> n;
    while(n--) {
        int a; cin >> a;
        int pos = lower_bound(b.begin(),b.end(),a) - b.begin();
        cout << b[pos] << ' ';
    }

    return 0;
}