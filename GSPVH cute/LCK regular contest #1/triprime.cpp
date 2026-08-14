#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 4e4 + 7;
int n,prime[MM];
vector<int> primes;

void sieve()
{
    const int lim = 31622;
    for(int i = 2;i < lim;i++)
        prime[i] = 1;
    for(int i = 2;i * i < lim;i++)
        if(prime[i])
            for(int j = i * i;j < lim;j += i)
                prime[j] = 0;

    for(int i = 2;i < lim;i++)
        if(prime[i])
            primes.push_back(i);
}

bool isprime(int k)
{
    if(k < 2) return 0;
    if(k < 31622) return prime[k];
    for(int i = 2;i * i <= k;i++)
        if(k % i == 0) return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "triprime"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    ll n; cin >> n;
    for(int i = 0;i < primes.size();i++) {
        for(int j = i + 1;j < primes.size();j++) {
            ll a = primes[i], b = primes[j];
            if(n % a != 0 || n % b != 0) continue;
            ll c = n / (a * b);
            if(isprime(c) && c != a && c != b) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}