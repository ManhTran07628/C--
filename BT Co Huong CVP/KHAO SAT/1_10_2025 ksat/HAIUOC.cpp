#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e6+7;
int n,a[MM],prime[MM];
vector<int> primes;

void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(int i = 2;i*i < MM;i++) 
        if(prime[i])
            for(int j = i*i;j < MM;j+=i)
                prime[j] = 0;

    for(int i = 2;i < MM;i++) 
        if(prime[i])
            primes.push_back(i);    
}

void solve()
{
    sieve();
    for(int i = 1;i <= n;i++) {
        int pos = upper_bound(primes.begin(),primes.end(),a[i]) - primes.begin();
        cout << primes[pos-1] << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "HAIUOC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    solve();
    return 0;
}