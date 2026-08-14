#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
int p[N];
void sieve()
{
    fill(p+1,p+N+1,1);
    p[0] = p[1] = 0;
    for(int i = 2;i <= sqrt(N);i++)
        if(p[i])   
            for(int j = i*2;j <= N;j+=i)
                p[j] = 0;
}


bool check(ll k)
{
    ll x = int(sqrt(k));
    if(x * x != k) return 0;
    if(p[x]) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a;
        cin >> a;
        if(check(a) && a != 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
    return 0;
}