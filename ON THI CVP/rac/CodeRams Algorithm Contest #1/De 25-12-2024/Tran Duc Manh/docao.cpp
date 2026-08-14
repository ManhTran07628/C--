#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],p[N];
ll n,h;
void sieve()
{
    for(int i = 1;i <= N;i++) p[i] = 1;
    p[1] = p[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(p[i])
            for(ll j = i*i;j <= N;j+=i)
                p[j] = 0;
}

ll tongcs(ll k)
{
    ll ans = 0;
    while(k > 0) {
        ans += k % 10;
        k /= 10;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "docao"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> n >> h;
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(p[i] && tongcs(i) == h) {
            cout << i << '\n';
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}