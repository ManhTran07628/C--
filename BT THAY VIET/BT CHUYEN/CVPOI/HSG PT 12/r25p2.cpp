#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,k,a[MM],prime[MM],D[MM];

void sieve()
{

    for(int i = 2;i < MM;i++)
        prime[i] = 1;

    
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(int j = i * i;j < MM;j+=i)
                prime[j] = 0;
}

bool check(int k)
{
    int d = 1;
    while(k > 0) {
        d *= (k % 10);
        k /= 10;
    }
    return prime[d];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l,r;
    cin >> l >> r;
    sieve();
    int ans = 0;
    for(int i = l;i <= r;i++) {
        ans += check(i);
    }
    cout << ans;
    return 0;
}