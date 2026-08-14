#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int a[MM],b[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) cin >> b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,greater<int>());
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            res += max(a[i],b[i]);
        }
        cout << res << '\n';
    }
    return 0;
}