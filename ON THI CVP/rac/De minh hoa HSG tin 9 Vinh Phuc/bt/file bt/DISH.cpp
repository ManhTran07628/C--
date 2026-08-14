#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],ps[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    cin >> n >> p;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int min_pos = 0,l = 0,r = 0,sum = -1e18;
    for(int i = 1;i <= n;i++) {
        ps[i] = ps[i-1] + a[i];
        if(ps[i]-ps[min_pos] > sum) {
            sum = ps[i]-ps[min_pos];
            l = min_pos;
            r = i;
        }
        if(ps[i] < ps[min_pos]) min_pos = i;
    }
    if(sum < p) cout << -1;
    else cout << l+1 << ' ' << r;
    return 0;
}