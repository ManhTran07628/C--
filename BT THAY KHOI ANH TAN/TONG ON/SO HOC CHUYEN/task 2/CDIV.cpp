#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],check[MAXN];
int n;

void solve()
{
    for(int i = 1e6;i >= 1;i--) {
        int dd = 0;
        for(int j = i;j <= 1e6;j+=i) {
            dd += check[j];
            if(dd >= 2) break;
        }
        if(dd >= 2) {
            cout << i;
            return;
        }
    }
}

void brute_force()
{
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            ans = max(ans,__gcd(a[i],a[j]));
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        check[a[i]]++;
    }
    // brute_force();
    solve();
    return 0;
}