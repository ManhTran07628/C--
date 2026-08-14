#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0,x = 5;
    while(n >= x) {
        ans += n/x;
        n /= x;
    }
    cout << ans;
    return 0;
}