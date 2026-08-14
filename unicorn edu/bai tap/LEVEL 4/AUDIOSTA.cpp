#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e9
#define pii pair<int,int>
const int MM = 1e5+7;
int n,c;
int a[MM];

bool check(int length)
{
    int cnt = 1,fpos = 1;
    for(int i = 2;i <= n;i++) {
        if(a[i] - a[fpos] >= length) {
            cnt++;
            fpos = i;
        }
    }
    return cnt >= c;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    // cout << check(3);
    int L = 1,R = oo,ans = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << ans;
    return 0;
}