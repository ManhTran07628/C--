#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int MOD = 1e9+7;

int cntdiv(int k,int d)
{
    int cnt = 0;
    while(k > 0) {
        cnt += k / d;
        k /= d;
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        int p = 1e16;
        cout << cntdiv(p,2) << '\n';
        int ans = min(cntdiv(b,5)-cntdiv(a-1,5),cntdiv(b,2)-cntdiv(a-1,2))%MOD;
        cout << ans << '\n';
    }
    return 0;
}