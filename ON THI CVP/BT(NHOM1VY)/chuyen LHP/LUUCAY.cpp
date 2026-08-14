#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    a[2] = 4;
    a[3] = 10;
    for(int i = 4;i <= 25;i++) {
        if(i % 2 == 1) {
            a[i] = a[i-2] * 10;
        }
        else a[i] = a[i-1] * sqrt(10) + 1;
    }
    ll n;
    cin >> n;
    ll ans = 0;
    ll p = upper_bound(a+1,a+26,n)-a-1;
    for(int i = 2;i <= p;i++) {
        ans += (a[i]-a[i-1])*(i-1);
    }
    ans += (n-a[p]+1)*(p);
    cout << ans;
    return 0;
}  