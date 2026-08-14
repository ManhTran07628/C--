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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= k;i++) {
        cin >> a[i];
    }
    ll L = 1,R = 1e16,ans = 0;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll soqua = 0;
        for(int i = 1;i <= k;i++) {
            soqua = soqua + a[i] / mid + (a[i] % mid != 0);
        }
        if(soqua <= n) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}