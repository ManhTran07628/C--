#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e7+7;
bool prime[MAXN];
vector<int> primes;
void sieve()
{
    fill(prime+1,prime+MAXN+1,1);
    prime[0]=prime[1]=0;
    for(int i = 2;i*i < MAXN;i++)   
        if(prime[i])
            for(int j = i*2;j < MAXN;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN;i++) if(prime[i]) primes.push_back(i);
}

bool check(int k)
{
    if(k < 2) return 0;
    for(int p:primes) {
        if(p*p > k) return 1;
        if(k % p == 0) return 0;
    }
    return 1;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n,cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        if(a < 1e7) 
        {
            if(prime[a]) cnt++;
        }
        else {
            if(check(a)) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}