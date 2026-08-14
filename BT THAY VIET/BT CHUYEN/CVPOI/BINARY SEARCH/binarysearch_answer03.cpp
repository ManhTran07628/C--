#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,k;
int x[MM];

bool check(int len)
{
    int used = 1,curpos = x[1] + len;
    for(int i = 1;i <= n;i++) {
        if(curpos - len <= x[i] && x[i] <= curpos + len) continue;
        else {
            used++;
            // curpos += len * 2 + 1;
            curpos = x[i] + len;
        }
    }
    return used <= k;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> x[i];
    sort(x+1,x+n+1);
    int L = 1,R = 1e9,ans = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}