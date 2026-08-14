#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll n;
ll tongcs(ll k)
{
    ll sum = 0;
    while(k > 0)  {
        sum += k%10;
        k /= 10;
    }
    return sum;
}

void sub1()
{
    ll x = 1;
    while(x <= 10000000) {
        if(tongcs(x)+x == n) {
            cout << x;
            return;
        }
        x++;
    }
    cout << -1;
}

void sub2()
{
    ll ans = -1;
    for(int i = 1;i <= 162;i++) {
        if(i > n) break;
        ll x = n - i;
        if(tongcs(x)+x == n) {
            if(ans == -1) ans = x;
            else ans = min(ans,x);
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n <= 1000000) sub1();
    else sub2();
    return 0;
}