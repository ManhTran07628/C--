#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],d[MAXN],ps[MAXN];
int n,r,k;

int check(int h)
{
    for(int i = 1;i <= n;i++) d[i] = 0;
    int cost = 0,add = 0;
    for(int i = 1;i <= n;i++) {
        add += d[i];
        int left = max(1ll,i-r),right = min(i+r,n);
        int current = add+ps[right]-ps[left-1];
        if(current < h) {
            int need = h-current;
            if(need+cost > k) return 0;
            cost += need;
            int pos = min(i+r*2,n);
            d[pos+1] -= need;
            add += need;
        }
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> k;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    int l = 0,r = 1e15;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}