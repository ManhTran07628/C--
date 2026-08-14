#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
// 31622
int prime[MM];
vector<int> primes;
void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(int i = 2;i * i < MM;i++)
        if(prime[i])
            for(int j = i * i;j < MM;j += i)
                prime[j] = 0;
    
    for(int i = 2;i < MM;i++)   
        if(prime[i] && i <= 31622) primes.push_back(i);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cout << primes.size();
    return 0;
}