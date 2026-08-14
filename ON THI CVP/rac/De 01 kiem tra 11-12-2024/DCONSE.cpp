#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+3;
const int MM = 5e6;
ll prime[N],f[N],a[N];
vector<ll> v;

ll cntdiv(ll n)
{
    map<ll,ll> b;
    while(n != 1) {
        b[prime[n]]++;
        n /= prime[n];
    }
    ll cnt = 1;
    for(auto c:b) {
        cnt *= (c.se+1);
    }
    return cnt;
}


int main()
{
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    for(int i = 2;i < sqrt(N);i++) {
        if(prime[i] == 0) {
            for(ll j = i*i;j < N;j+=i) {
                if(prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
    for(int i=0;i<N;i++)
        if(prime[i] == 0) prime[i] = i;
    ll C,n,p;
    cin >> C;
    cin >> n >> p;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n-2;i++) {
        ll m = cntdiv(__gcd(__gcd(a[i],a[i+1]),a[i+2]));
        f[i] = m;
    }
    if(C == 1) {
        ll cnt = 0;
        for(int i = 1;i <= n-2;i++) {
            if(f[i] <= p) cnt++;
        }
        cout << cnt;
    }
    else {
        int ans=0,cnt=0;
        for(int i=1;i<=n-2;i++)
        {
            if(f[i]<=p)
            {
                if(cnt==0) cnt=3;
                else cnt++;
            }
            else cnt=0;
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
