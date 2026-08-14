#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
map<ll,ll> lt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0,ans = 0;
    lt[0] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
        // if(a[i-1] == a[i]) ans--;
        ans += lt[sum];
        lt[sum]++;
        if(sum-a[i] == sum) ans--;
    }
    cout << ans;
    return 0;
}