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
    ll ans = (b-1)/(b-a)*(b-a);
    cout << ans-a;
    return 0;
}