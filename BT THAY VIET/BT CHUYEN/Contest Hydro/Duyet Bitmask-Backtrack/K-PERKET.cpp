#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int s[15],b[15];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s[i] >> b[i];
    }
    int ans = LLONG_MAX;
    for(int mask = 1;mask < (1 << n);mask++) {
        int spicy = 1,bitter = 0;
        for(int i = 0;i < n;i++) {
            if((mask>>i) & 1) {
                spicy *= s[i+1];
                bitter += b[i+1];
            }
        }
        ans = min(ans,abs(spicy-bitter));
    }
    cout << ans;
    return 0;
}