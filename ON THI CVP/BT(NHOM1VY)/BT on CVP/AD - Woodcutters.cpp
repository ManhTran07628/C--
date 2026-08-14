#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<ll,ll> p[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> p[i].fi >> p[i].se;
    }
    if(n == 1) {
        cout << 1;
        return 0;
    }
    int ans = 2;
    for(int i = 2;i < n;i++) {
        if(p[i].fi - p[i].se > p[i-1].fi) {
            ans++;
            continue;
        }
        if(p[i].fi + p[i].se < p[i+1].fi) {
            p[i].fi = p[i].fi + p[i].se;
            ans++;
        }
    }
    cout << ans;
    return 0;
}