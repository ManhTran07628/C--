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
    ll m,k,n;
    cin >> m >> k >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = n,sum = 0;
    ll i = 1,j = 1;
    while(i <= n && j <= n) {
        while((sum+a[j])/k < m && j <= n) {
            sum += a[j];
            j++;
        }
        ans = min(ans,j-i+1);
        sum -= a[i];
        i++;
    }
    cout << ans;
    return 0;
}