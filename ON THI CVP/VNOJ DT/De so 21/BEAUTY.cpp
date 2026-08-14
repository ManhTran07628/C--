#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+2;
ll a[N];
vector<ll> f;
void sieve()
{
    for(int i = 1;i <= N;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(a[i])
            for(int j = i*i;j <= N;j+=i) 
                a[j] = 0;
}

ll check(ll k)
{
    ll cnt = 0;
    while(k > 0) {
        ll tmp = k % 10;
        cnt = cnt + tmp * tmp;
        k /= 10;
    }
    if(a[cnt]) return 1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BEAUTY"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    for(int i = 1;i <= 1000000;i++) {
        if(check(i)) {
            f.push_back(i);
        }
    }
    ll n;
    while(cin >> n) {
        cout << f[n-1] << '\n';
    }
    return 0;
}