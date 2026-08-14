#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<ll,ll> lt;
ll a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    ll ans = 1e6;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(lt[a[i]] > i) {
            ans = min(ans,a[i]);
        }
        lt[a[i]] = i+k;
    }
    if(ans != 1e6) cout << ans;
    else cout << -1;
    return 0;
}