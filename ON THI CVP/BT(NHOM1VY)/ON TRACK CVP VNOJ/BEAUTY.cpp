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
        a[i] += a[i-1];
    }
    ll ans = -1e18;
    for(int i = 1;i <= n;i++) {
        for(int j = n;j >= i;j--) {
            if((j-i+1)%2==0 && (j-i+1) >= 4) ans = max(ans,a[j]-a[i-1]);
        }
    }
    cout << ans;
    return 0;
}