#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e7+7;
int MOD = 1e9+7;
int prime[MAXN];
vector<int> primes;
void sieve()
{
    for(int i = 2;i < MAXN;i++) prime[i] = 1;
    for(int i = 2;i*i < MAXN;i++)
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN;i++) 
        if(prime[i]) primes.push_back(i);
}

int binpow(int a,int b)
{
    int ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int legendary(int p,int n)
{
    int cnt = 0;
    while(n > 0) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}

void solve()
{
    sieve();
    int n;
    cin >> n;
    int ans = 1;
    for(int p:primes) {
        int cnt = legendary(p,n);
        if(cnt % 2) cnt--;
        ans = (ans*binpow(p,cnt))%MOD;
    }
    cout << ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}