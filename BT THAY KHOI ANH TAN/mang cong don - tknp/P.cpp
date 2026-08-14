#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,Ta,Tb,k;
    cin >> n >> m >> Ta >> Tb >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    if(k >= n || k >= m) {
        cout << -1;
        return 0;
    }
    ll ans = -1;
    for(int i = 1;i <= k+1;i++) {
        ll move1 = lower_bound(b+1,b+m+1,a[i]+Ta)-b;
        ll move2 = move1+(k-i+1);
        if(move2 > m) {
            cout << -1;
            return 0;
        }
        ans = max(ans,b[move2]+Tb);
    }
    cout << ans;
    return 0;
}
