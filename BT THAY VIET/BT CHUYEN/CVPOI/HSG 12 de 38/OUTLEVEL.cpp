#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 100 + 7;
int f[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,n; cin >> k >> n;
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= n;j++) {
            int u; cin >> u;
            f[i][u] = j;
        }
    }

    int cnt = 0;
    for(int a = 1;a <= n;a++) {
        for(int b = a + 1;b <= n;b++) {

            bool ok1 = 1, ok2 = 1;

            for(int i = 1;i <= k;i++) {
                if(f[i][a] < f[i][b]) continue;
                ok1 = 0;
            }

            for(int i = 1;i <= k;i++) {
                if(f[i][b] < f[i][a]) continue;
                ok2 = 0;
            }

            if(ok1 || ok2) {
                // cout << a << ' ' << b << '\n';
                cnt++;
            }

        }
    }
    cout << cnt;
    return 0;
}