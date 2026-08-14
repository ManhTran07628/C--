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
    int n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = n+1,sum = 0;
    for(ll i = 1,j = 1;j <= n;i++) {
        while(sum < s) {
            sum += a[j];
            j++;
        }
        ans = min(ans,j-i);
        sum -= a[i];
    }
    if(ans == n+1) cout << 0;
    else cout << ans;
    return 0;
}