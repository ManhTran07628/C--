#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<ll,ll> lt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a;
        cin >> a;
        lt[a]++;
    }
    cin >> m;
    ll ans = 0;
    for(int i = 1;i <= m;i++) {
        ll b;
        cin >> b;
        if(lt[b] != 0) ans++;
    }
    cout << ans;
    return 0;
}
