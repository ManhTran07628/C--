#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ull unsigned long long
const int N = 1e6+7;
ll a[N];
ull n;

ull binpow(ull b)
{
    ull a = 2;
    ull ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

ull solve(ull n)
{
    ll cnt = 0;
    while(n > 1) {
        ll m = ceil(log2(n+1)-1);
        ull x = binpow(m);
        n -= x;
        cnt++;
    }
    if(n == 1) return cnt % 2 == 0;
    else return cnt % 2 == 1;
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
    ll t;
    cin >> t;
    while(t--)
    {
        ull n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}