#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e7+7;
const int Nsieve = 5e6+3;
bool prime[MAXN];
int ps[MAXN];

void sieve()
{
    fill(prime+1,prime+Nsieve+1,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i < Nsieve;i++)
        if(prime[i])
            for(int j = i*i;j < Nsieve;j+=i)
                prime[j] = 0;
}
bool ispalind(int k)
{
    int d = 0,k1 = k;
    while(k > 0) {
        int digit = k % 10;
        d = d * 10 + digit;
        k /= 10;
    }
    return d == k1;
}

bool check(int k)
{
    int tongcs = 0,tichcs = 1;
    while(k > 0) {
        int digit = k % 10;
        tongcs += digit;
        tichcs *= digit;
        k /= 10;
    }
    if(prime[tongcs] && ispalind(tichcs)) return 1;
    return 0;
}

void solve()
{
    sieve();
    for(int i = 1;i < Nsieve;i++) {
        if(check(i)) ps[i]++;
        ps[i] += ps[i-1];
    }
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << ps[r] - ps[l-1] << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "ABSOLUTECINEMA"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    solve();
    return 0;
}