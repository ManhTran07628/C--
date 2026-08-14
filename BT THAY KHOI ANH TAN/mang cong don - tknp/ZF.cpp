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
    ll n,m; 
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
    }
    sort(a+1,a+m+1);
    ll l = 1,r = 1e10,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll sum = 0;
        for(int i = 1;i <= m;i++) {
            sum = sum + (a[i]+mid-1) / mid;
            if(sum > n) break;
        }
        if(sum <= n) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}