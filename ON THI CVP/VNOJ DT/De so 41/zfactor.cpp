#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll a[N],min_prime[N];

void sieve()
{
    for(int i = 2;i < sqrt(N);i++) {
        if(min_prime[i] == 0) {
            for(ll j = i*2;j < N;j+=i) {
                if(min_prime[j] == 0) 
                    min_prime[j] = i;
            }
        }
    }
    for(int i = 2;i < N;i++) {
        if(min_prime[i] == 0) min_prime[i] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "zfactor"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    int n,k;
    cin >> n >> k;
    for(int i = 2;i <= k;i++) {
        a[min_prime[i]]++;
    }
    while(n--) {
        ll a1;
        cin >> a1;
        cout << a[a1] << '\n';
    }
    return 0;
}