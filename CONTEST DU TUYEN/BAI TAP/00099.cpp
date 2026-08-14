#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,a[MM];
ll s = 0;

bool check(int k)
{
    ll val = s / k, cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i] <= val) {
            cnt++;
        }
    }
    return cnt >= k;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s += a[i];
    }

    int l = 0, r = n, ans = 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << n - ans;

    return 0;
}