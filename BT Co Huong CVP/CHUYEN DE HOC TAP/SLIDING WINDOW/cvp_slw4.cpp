#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,k,a[MM],cnt1[MM],cnt2[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll res = 0,dif1 = 0,dif2 = 0;
    for(int i = 1,j = 1,d = 1;d <= n;d++) {
        if(cnt1[ a[d] ] == 0) dif1++;
        cnt1[ a[d] ]++;

        if(cnt2[ a[d] ] == 0) dif2++;
        cnt2[ a[d] ]++;

        while(i <= n && dif1 > k - 1) {
            if(cnt1[ a[i] ] == 1) dif1--;
            cnt1[ a[i] ]--;
            i++;
        }

        while(j <= n && dif2 > k) {
            if(cnt2[ a[j] ] == 1) dif2--;
            cnt2[ a[j] ]--;
            j++;
        }

        // cout << i << ' ' << j << ' ' << d << '\n';
        if(i > j) res += i - j;
    }
    cout << res;
    return 0;
}