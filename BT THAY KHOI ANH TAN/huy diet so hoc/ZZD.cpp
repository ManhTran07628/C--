#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 2e7+7;
const int Nsieve = 2e7;
int prime[MAXN];
int id = 1;
vector<int> primes;
void sieve()
{
    fill(prime+1,prime+Nsieve,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i < Nsieve;i++)   
        if(prime[i])
            for(int j = i*i;j < Nsieve;j+=i)  
                prime[j] = 0;
    for(int i = 2;i < Nsieve;i++) 
        if(prime[i]) primes.push_back(i);
}
bool Isprime(int k)
{
    if(k < 2) return 0;
    for(auto i:primes) {
        if(i*i > k) return 1;
        if(k % i == 0) return 0;
    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "ZZD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    int n;
    cin >> n;
    int cnt = 0;
    for(auto i:primes) {
        if(i*2 > n) break;
        int p = n-i;
        if(p >= Nsieve) {
            if(Isprime(p)) cnt++;
        }
        else
            if(prime[p]) cnt++; 
    }
    cout << cnt;
    return 0;
}