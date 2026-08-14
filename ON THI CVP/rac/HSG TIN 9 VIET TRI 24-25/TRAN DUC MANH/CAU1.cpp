#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int p[N];
void sieve()
{
    for(int i = 1;i <= N;i++) p[i] = 1;
    p[0] = p[1] = 0;
    for(int i = 1;i <= sqrt(N);i++)
        if(p[i])
            for(ll j = i*i;j <= N;j+=i) 
                p[j] = 0;
}

ll check(ll k)
{
    ll ans = 0;
    for(int i = 1;i <= sqrt(k);i++) {
        if(k % i == 0) {
            ans += i;
            if(k/i != i) ans += k/i;
        }
    }
    if(p[ans]) return 1;
    else return 0;
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
    ll l,r;
    cin >> l >> r;
    ll cnt = 0;
    for(int i = l;i <= r;i++) {
        if(check(i)) cnt++;
    }
    cout << cnt;
    return 0;
}