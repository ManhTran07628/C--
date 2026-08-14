#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int MM = 1e9+7;

int counts(int k,int d)
{
    int cnt = 0;
    while(k > 0) {
        cnt += k / d;
        cnt = cnt % MM;
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
        int d1 = counts(b,5)-counts(a-1,5);
        int d2 = counts(b,2)-counts(a-1,2);
        cout << min(d1,d2) << '\n';
    }
    return 0;
}