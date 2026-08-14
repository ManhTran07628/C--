#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll p[N];
map<ll,int> st;

void sieve()
{
    fill(p+1,p+N+1,1);
    p[1] = p[0] = 0;
    for(int i = 1;i*i < N;i++)
        if(p[i])
            for(int j = i*i;j < N;j+=i)
                p[j] = 0;
}

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0) {
        if(b & 1 == 0) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    ll n,m;
    cin >> n >> m;
    int m1 = m;
    for(int i = 2;i*i <= m1;i++) {
        while(m % i == 0) {
            st[i]++;
            m /= i;
        }
    }
    if(m > 1) {
        st[m]++;
    }
    ll ans = 1e9;
    for(auto i:st) {
        ll cnt = 0,k = 1;
        int x = i.fi;
        while(binpow(x,k) <= n) {
            ll f = binpow(x,k);
            cnt = cnt + (n / f);
            k++;
        }
        ans = min(ans,cnt/i.se);
    }
    cout << ans;
    return 0;
}
