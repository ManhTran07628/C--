#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int b[MAXN],a[MAXN];
bool prime[MAXN];
vector<int> primes;
map<int,int> factors;
int n;
void sieve()
{
    for(int i = 2;i < MAXN;i++) 
        prime[i] = 1;
    for(int i = 2;i*i < MAXN;i++)
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN;i++) 
        if(prime[i])
            primes.push_back(i);
}
int solve()
{
    for(auto p:primes) {
        if(p > k) break;
        while(k % p == 0) {
            factors.push_back(p);
            k /= p;
        }
    }
    for (int x : factors) {
        cout << x << '\n';
        bool ok = 1;
        for(int i = n;i > 1;i--) {
            if(b[i] % b[i-1] != 0) {
                if(b[i-1]/x != 0 && b[i] % (b[i-1]/x) != 0) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) return x;
    }
    return 2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> b[i];
        }
        cout << solve() << '\n';
    }
    return 0;
}