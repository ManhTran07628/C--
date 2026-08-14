#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    ll ans = 0,m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] < 0 && k > 0) {
            a[i] *= -1;
            k--;
        }
    }
    sort(a+1,a+n+1);
    if(k % 2 == 1 && k > 0) a[1] *= -1;
    for(int i = 1;i <= n;i++) ans += a[i];
    cout << ans;
    return 0;
}