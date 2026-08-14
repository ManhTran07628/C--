#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int prime[MAXN];
vector<int> primes;
map<int,int> cntdiv;
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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n,m;
    cin >> n >> m;
    for(auto p:primes) {
        if(m < p) break;
        while(m % p == 0) {
            cntdiv[p]++;
            m /= p;
        }
    }
    int ans = LLONG_MAX;
    for(auto [p,cnt]:cntdiv) {
        int k = n,temp = 0;
        while(k > 0) {
            temp += k/p;
            k /= p;
        }
        ans = min(ans,temp);
    }
    cout << ans;
    return 0;   
}