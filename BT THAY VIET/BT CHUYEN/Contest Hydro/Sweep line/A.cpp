#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,d[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int lim = 0;
    for(int i = 1;i <= n;i++) {
        int l,r;
        cin >> l >> r;
        d[l]++;
        d[r]--;
        lim = max(lim,r);
    }
    for(int i = 1;i <= lim;i++) d[i] += d[i-1];
    for(int l = 1,r = 1;r < lim;) {
        while(r <= lim && !d[r]) {
            r++;
            l++;
        }
        while(r <= lim && d[r]) r++;
        cout << l << ' ' << r << '\n';
        l = r;
    }
    return 0;
}