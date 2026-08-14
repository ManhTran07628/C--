#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("MOVE.inp","r",stdin);
    freopen("MOVE.out","w",stdout);
    ll a,b,k;
    cin >> a >> b >> k;
    ll ans1 = 0,ans2 = 0;
    ans1 += a / k;
    if(a % k != 0) ans1++;
    ans2 += b / k;
    if(b % k != 0) ans2++;
    ll cnt = 0;
    if(ans1 > ans2) cnt = ans1*2-1;
    else cnt = ans2*2;
    cout << cnt;
    return 0;
}
