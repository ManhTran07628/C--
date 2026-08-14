#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
ll t[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> t[i];
    }
    ll l = 1,r = 1e15,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll time = 0;
        for(int i = 1;i <= n;i++) {
            time += mid/t[i];
        }
        if(time >= m) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}