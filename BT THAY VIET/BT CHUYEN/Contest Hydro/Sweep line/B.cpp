#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,d[MM],v[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int lim = 0;
    for(int i = 1;i <= n;i++) {
        int l,r;
        cin >> l >> r;
        v[l-1] = v[r] = 1;
        d[l]++;
        d[r+1]--;
        lim = max(lim,r);
    }
    int pre_pos = 1,ans = 0;
    for(int i = 1;i <= lim;i++) {
        d[i] += d[i-1];
        if(v[i]) {
            ans = max(ans,d[i]*(i-pre_pos));
            pre_pos = i+1;
        }
    }
    cout << ans;
    return 0;
}