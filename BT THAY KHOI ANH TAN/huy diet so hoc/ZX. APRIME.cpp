#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
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


void solve(int a)
{
    int cnt = 0;
    for(int i = 0;i < primes.size();i++) {
        int p3 = pow(primes[i],3);
        if(p3>a) break;
        for(int j = 0;j < primes.size();j++) {
            int p2 = pow(primes[j],2);
            if(p2>a) break;
            if(a-p3-p2 > 0 && prime[a-p3-p2]) cnt++;
        }
    }
    cout << cnt << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        solve(a);
    }
    return 0;   
}