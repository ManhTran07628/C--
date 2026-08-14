#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e6+7;
pii a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    int L = oo, R = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }

    int ans1 = 0, ans2 = 0;
    sort(a+1,a+n+1);
    for(int i = 2;i <= n;i++) {
        if(a[i].fi <= a[i-1].se + 1)
    }
    return 0;
}