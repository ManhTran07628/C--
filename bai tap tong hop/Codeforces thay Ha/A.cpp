#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
int t,n,a[MM],cnt[MM],dem = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(cnt[a[i]] == 1) dem++;
        cnt[a[i]]++;
    }
    int len = n+n,i = 0,j = 0;
    for(int l = 1,r = 1;l <= n;l++) {
        while(dem > 0 && r <= n) {
            cnt[a[r]]--;
            if(cnt[a[r]] == 1) dem--;
            r++;
        }
        if(dem > 0) break;
        if(r-l+1 < len) {
            i = l, j = r-1;
            len = r-l+1;
        }
        // cout << l << ' ' << r << '\n';
        cnt[a[l]]++;
        if(cnt[a[l]] > 1) dem++;
    }
    cout << i-1 << ' ' << j-1;
    return 0;
}