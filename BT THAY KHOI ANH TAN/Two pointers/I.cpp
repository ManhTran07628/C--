#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,q;
    cin >> n >> k >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = 1,ans = 0,d = 0;
    while(i <= n && j <= n) {
        d = max(d,a[j]);
        if(d <= q && j-i+1 >= k)ans = ans + (j-i+1)-k+1;
        if(d > q) {
            d = 0;
            i = j+1;
        }
        j++;
    }
    cout << ans;
    return 0;
}