#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int n,k,l = 1,r = 0,val = 0;


bool check(int vmax)
{
    int cnt = 1,sum = 0;
    for(int i = 1;i <= n;i++) {
        sum += a[i];
        if(sum > vmax) {
            cnt++;
            sum = a[i];
            if(sum > vmax) return 0;
        }
        if(cnt > k) return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        r += a[i];
    }
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            val = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << val;
    return 0;
}