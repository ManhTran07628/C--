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
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    int t = 0;
    while (a != b) {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    cout << ans;
    return 0;
}