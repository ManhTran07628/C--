#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e5 + 7;
int t;
int n,a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll ss = 0;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int m = n / 2;
        ll sum = 0,maxs = oo;
        for(int i = 1,j = 1;j <= n;j++) {
            ss += a[j];
            sum += a[j];
            if(j - i + 1 > m + 1) {
                sum -= a[i];
                i++;
            }
            if(j - i + 1 == m + 1) {
                maxs = min(maxs,sum);
            }
        }
        cout << maxs << ' ' << ss - maxs << '\n';
        

    }
    return 0;
}