#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int x[MAXN];
int n,k;

bool check(int r)
{
    int i = 1,pos = x[1]+r,cnt = 1;
    while(i <= n) {
        if(pos-r <= x[i] && x[i] <= pos+r) i++;
        else {
            cnt++;
            if(cnt > k) return 0;
            pos = x[i]+r;
        } 
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
    }
    sort(x+1,x+n+1);
    int l = 0,r = 1e9,ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}