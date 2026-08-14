#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int lan1 = (n-2)/2,lan2 = n-1;
    ll ans = 0;
    for(int i = 4;i <= n;i+=2) {
        ans += a[i];
    }
    cout << ans + lan1*a[1]+lan2*a[2];
    return 0;
}