#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 5e4+7;
int l,n,m,d[MM];

bool check(int length)
{
    int used = 0,prev = 1;
    for(int i = 2;i <= n;i++) {
        if(used > m) return 0;
        if(d[i] - d[prev] < length) used++;
        else prev = i;
    }
    return used <= m;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> n >> m;
    d[1] = 0;
    for(int i = 2;i <= n+1;i++) cin >> d[i];
    d[n + 2] = l; n += 2;
    sort(d+1,d+n+1);
    // for(int i = 1;i <= n;i++) cout << d[i] << ' ';
    int L = 0,R = 1e9,ans = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << ans;
    return 0;
}