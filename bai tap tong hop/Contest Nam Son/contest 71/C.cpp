#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<int,int> a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    while(m--) {
        int k;
        cin >> k;
        int p = lower_bound(a+1,a+n+1,make_pair(k+1,0))-a;
        int ans = 0;
        if(p == n+1 && a[p-1].se <= k) ans = -1;
        else {
            if(a[p-1].fi <= k && k < a[p-1].se) ans = 0;
            else ans = a[p].fi-k;
        }
        cout << ans << '\n';
    }
    return 0;
}