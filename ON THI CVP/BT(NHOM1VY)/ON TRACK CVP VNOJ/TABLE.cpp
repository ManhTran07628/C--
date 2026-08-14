#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll a = 1,b = n;
    ll x = int(sqrt(n));
    ll y = (n+x-1)/x;
    if(a + b > x + y) {
        a = x;b = y;
    }
    x++;
    y = (n+x-1)/x;
    if(a + b > x + y) {
        a = x;b = y;  
    }
    cout << a << ' ' << b;
    return 0;

}